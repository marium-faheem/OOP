#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

class MediaContent {
private:
    int    contentID;
    string title;
    string language;
    double imdbRating;
    int    releaseYear;

public:
    MediaContent(int id, const string& t, const string& l,
                 double r, int y)
        : contentID(id), title(t), language(l),
          imdbRating(r), releaseYear(y) {}

    virtual ~MediaContent() {}  
    int    getContentID()   const { return contentID;   }
    string getTitle()       const { return title;        }
    string getLanguage()    const { return language;     }
    double getImdbRating()  const { return imdbRating;   }
    int    getReleaseYear() const { return releaseYear;  }

    void setTitle(const string& t)  { title = t;       }
    void setImdbRating(double r)    { imdbRating = r;  }

    virtual void   display()        const = 0;
    virtual string getContentType() const = 0;
    virtual double getDuration()    const = 0;

    virtual void play() const {
        cout << "Now playing: " << title
             << " [" << getContentType() << "]\n";
    }
};

class StreamingEngine {
private:
    string serverRegion;
    int    bufferSizeMB;

public:
    StreamingEngine(const string& region, int buf)
        : serverRegion(region), bufferSizeMB(buf) {}

    virtual ~StreamingEngine() {}

    string getServerRegion() const { return serverRegion; }
    int    getBufferSize()   const { return bufferSizeMB; }

    virtual void   stream()             const = 0;
    virtual string getQuality()         const = 0;
    virtual int    getBitrate()         const = 0;
    virtual void   adjustBandwidth(int)       = 0;

    virtual void showStreamInfo() const {
        cout << "  Server:"  << serverRegion
             << " | Buffer:" << bufferSizeMB << "MB"
             << " | Quality:" << getQuality()
             << " | " << getBitrate() << " kbps.\n";
    }
};

class User {
private:
    int    userID;
    string name;
    string email;
    string password; 

public:
    User(int id, const string& n, const string& e, const string& p)
        : userID(id), name(n), email(e), password(p) {}

    virtual ~User() {}

    int    getUserID() const { return userID; }
    string getName()   const { return name;   }
    string getEmail()  const { return email;  }

    bool checkPassword(const string& p) const { return password == p; }

    void setName(const string& n)  { name = n;  }
    void setEmail(const string& e) { email = e; }

    virtual string getAccountType() const = 0;
    virtual bool   canDownload()    const = 0;
    virtual bool   canWatchHD()     const = 0;
    virtual int    getScreenLimit() const = 0;
    virtual void   displayProfile() const = 0;

    virtual void showWelcome() const {
        cout << "Welcome, " << name
             << "! [" << getAccountType() << "]\n";
    }
};

class Episode : public MediaContent {
private:
    int    seasonNo;
    int    episodeNo;
    double durationMins;
    string synopsis;

public:
    Episode(int id, const string& t, const string& l,
            double r, int y, int s, int e, double d,
            const string& syn)
        : MediaContent(id, t, l, r, y),
          seasonNo(s), episodeNo(e),
          durationMins(d), synopsis(syn) {}

    int    getSeasonNo()  const { return seasonNo;  }
    int    getEpisodeNo() const { return episodeNo; }
    string getSynopsis()  const { return synopsis;  }

    string getContentType() const override { return "Episode"; }
    double getDuration()    const override { return durationMins; }

    void display() const override {
        cout << "    Season " << seasonNo << ", Episode " << episodeNo << " - "
             << getTitle() << " (" << durationMins << "m)"
             << " - " << synopsis << "\n";
    }
    void play() const override {
        cout << "Now watching - Season " << seasonNo << ", Episode " << episodeNo << ": \"" << getTitle() << "\"\n";
    }
};

class Movie : public MediaContent {
private:
    string         genre;
    double         durationMins;
    string         director;
    string         ageRating;
    vector<string> cast;

public:
    Movie(int id, const string& t, const string& l,
          double r, int y, const string& g, double d,
          const string& dir, const string& age)
        : MediaContent(id, t, l, r, y),
          genre(g), durationMins(d),
          director(dir), ageRating(age) {}

    string getGenre()    const { return genre;    }
    string getDirector() const { return director; }
    string getAgeRating()const { return ageRating;}
    void   addCast(const string& a) { cast.push_back(a); }

    string getContentType() const override { return "Movie"; }
    double getDuration()    const override { return durationMins; }

    void display() const override {
        cout << "\n  ---- Movie Details ----\n";
        cout << "  ID          : " << getContentID()  << "\n";
        cout << "  Title       : " << getTitle()       << "\n";
        cout << "  Genre       : " << genre            << "\n";
        cout << "  Director    : " << director         << "\n";
        cout << "  Runtime     : " << durationMins     << " mins\n";
        cout << "  Language    : " << getLanguage()    << "\n";
        cout << "  IMDB rating : " << getImdbRating()  << "/10\n";
        cout << "  Released    : " << getReleaseYear() << "\n";
        cout << "  Age rating  : " << ageRating        << "\n";
        if (!cast.empty()) {
            cout << "  Cast        : ";
            for (const auto& a : cast) cout << a << "  ";
            cout << "\n";
        }
        cout << "  ----------------------\n";
    }

    void play() const override {
        cout << "Now playing \"" << getTitle() << "\" (" << durationMins << " minutes)\n";
    }
};

class Series : public MediaContent {
private:
    string          genre;
    int             totalSeasons;
    string          status;       
    vector<Episode> episodes;     

public:
    Series(int id, const string& t, const string& l,
           double r, int y, const string& g,
           int seasons, const string& s)
        : MediaContent(id, t, l, r, y),
          genre(g), totalSeasons(seasons), status(s) {}

    void addEpisode(const Episode& ep) { episodes.push_back(ep); }

    string getGenre()        const { return genre;                 }
    int    getTotalSeasons() const { return totalSeasons;          }
    string getStatus()       const { return status;                }
    int    episodeCount()    const { return (int)episodes.size(); }

    string getContentType() const override { return "Series"; }

    double getDuration() const override {
        double total = 0;
        for (const auto& ep : episodes) total += ep.getDuration();
        return total;
    }

    void display() const override {
        cout << "\n  ---- Series Details ----\n";
        cout << "  ID          : " << getContentID()  << "\n";
        cout << "  Title       : " << getTitle()       << "\n";
        cout << "  Genre       : " << genre            << "\n";
        cout << "  Seasons     : " << totalSeasons     << "\n";
        cout << "  Episodes    : " << episodes.size()  << "\n";
        cout << "  Status      : " << status           << "\n";
        cout << "  IMDB rating : " << getImdbRating()  << "/10\n";
        cout << "  Released    : " << getReleaseYear() << "\n";
        cout << "  Episodes:\n";
        for (const auto& ep : episodes) ep.display();
        cout << "  ------------------------\n";
    }

    void play() const override {
        if (!episodes.empty()) {
            cout << "Starting the first episode of \""
                 << getTitle() << "\"\n";
            episodes[0].play();
        } else {
            cout << "No episodes available for \""
                 << getTitle() << "\"\n";
        }
    }
};

class Documentary : public MediaContent {
private:
    string topic;
    string narrator;
    string productionHouse;
    double durationMins;
    bool   hasSubtitles;

public:
    Documentary(int id, const string& t, const string& l,
                double r, int y, const string& top,
                const string& nar, const string& prod,
                double d, bool subs)
        : MediaContent(id, t, l, r, y),
          topic(top), narrator(nar), productionHouse(prod),
          durationMins(d), hasSubtitles(subs) {}

    string getTopic()           const { return topic;           }
    string getNarrator()        const { return narrator;        }
    string getProductionHouse() const { return productionHouse; }
    bool   getHasSubtitles()    const { return hasSubtitles;    }

    string getContentType() const override { return "Documentary"; }
    double getDuration()    const override { return durationMins;  }

    void display() const override {
        cout << "\n  ---- Documentary Details ----\n";
        cout << "  ID          : " << getContentID()    << "\n";
        cout << "  Title       : " << getTitle()         << "\n";
        cout << "  Topic       : " << topic              << "\n";
        cout << "  Narrator    : " << narrator           << "\n";
        cout << "  Production  : " << productionHouse    << "\n";
        cout << "  Runtime     : " << durationMins       << " mins\n";
        cout << "  Language    : " << getLanguage()      << "\n";
        cout << "  IMDB rating : " << getImdbRating()    << "/10\n";
        cout << "  Released    : " << getReleaseYear()   << "\n";
        cout << "  Subtitles   : " << (hasSubtitles ? "Yes" : "No") << "\n";
        cout << "  ----------------------------\n";
    }

    void play() const override {
        cout << "Now streaming: \""
             << getTitle() << "\" narrated by " << narrator << "\n";
    }
};

class FreeUser : public User {
private:
    int  minutesWatched;
    int  monthlyLimit;
    int  adsWatchedToday;
    bool adSupported;

public:
    FreeUser(int id, const string& n,
             const string& e, const string& p)
        : User(id, n, e, p),
          minutesWatched(0), monthlyLimit(1800),
          adsWatchedToday(0), adSupported(true) {}

    int getRemainingMins() const { return monthlyLimit - minutesWatched; }

    void watchContent(int mins) {
        if (minutesWatched + mins > monthlyLimit) {
            cout << "You've used up all your free minutes for this month. Upgrade to Premium to keep watching without limits.\n";
            return;
        }
        minutesWatched += mins;
        adsWatchedToday++;
        cout << "Hang tight - a quick 30-second ad before your show...\n";
        cout << "You're all good! (" << getRemainingMins()
             << " minutes left for this month)\n";
    }

    string getAccountType() const override { return "Free";  }
    bool   canDownload()    const override { return false;   }
    bool   canWatchHD()     const override { return false;   }
    int    getScreenLimit() const override { return 1;       }

    void displayProfile() const override {
        cout << "\n  ---- Your M-FLIX Profile ----\n";
        cout << "  User ID     : " << getUserID()      << "\n";
        cout << "  Name        : " << getName()         << "\n";
        cout << "  Email       : " << getEmail()        << "\n";
        cout << "  Account type: " << getAccountType()  << "\n";
        cout << "  Max screens : " << getScreenLimit()  << "\n";
        cout << "  Downloads   : Not available on free plan\n";
        cout << "  HD streaming: Not included\n";
        cout << "  Ad-supported: Yes\n";
        cout << "  Watch time  : " << minutesWatched << " / " << monthlyLimit << " minutes used this month\n";
        cout << "  --------------------------------\n";
    }

    void showWelcome() const override {
        cout << "Hey " << getName() << "! You're on the free plan - " << getRemainingMins() << " minutes left this month.\n";
        cout << "Loving it? Upgrade to Premium anytime for unlimited, ad-free watching.\n";
    }
};

class PremiumUser : public User {
private:
    string         plan;
    double         monthlyPrice;
    int            screenLimit;
    bool           ultraHDEnabled;
    vector<string> downloadedTitles;
    string         renewalDate;

public:
    PremiumUser(int id, const string& n, const string& e,
                const string& p, const string& pl)
        : User(id, n, e, p), plan(pl), renewalDate("2025-12-01") {
        if (pl == "Basic")         { monthlyPrice=9.99;  screenLimit=2; ultraHDEnabled=false; }
        else if (pl == "Standard") { monthlyPrice=14.99; screenLimit=4; ultraHDEnabled=false; }
        else                       { monthlyPrice=19.99; screenLimit=6; ultraHDEnabled=true;  }
    }

    string getPlan()         const { return plan;          }
    double getMonthlyPrice() const { return monthlyPrice;  }
    bool   isUltraHD()       const { return ultraHDEnabled;}

    void downloadTitle(const string& t) {
        downloadedTitles.push_back(t);
        cout << "Saved for later: \"" << t << "\" is now available offline.\n";
    }
    void showDownloads() const {
        cout << "  Downloaded titles (" << downloadedTitles.size() << "):\n";
        for (int i=0; i<(int)downloadedTitles.size(); i++)
            cout << "  " << i+1 << ". " << downloadedTitles[i] << "\n";
    }

    string getAccountType() const override { return "Premium(" + plan + ")"; }
    bool   canDownload()    const override { return true;           }
    bool   canWatchHD()     const override { return true;           }
    int    getScreenLimit() const override { return screenLimit;    }

    void displayProfile() const override {
        cout << "\n  ---- Your M-FLIX Profile ----\n";
        cout << "  User ID     : " << getUserID()       << "\n";
        cout << "  Name        : " << getName()          << "\n";
        cout << "  Email       : " << getEmail()         << "\n";
        cout << "  Account type: " << getAccountType()   << "\n";
        cout << "  Plan        : " << plan               << "\n";
        cout << "  Monthly fee : $" << monthlyPrice << "/month\n";
        cout << "  Max screens : " << screenLimit        << "\n";
        cout << "  Downloads   : Yes - save titles for offline\n";
        cout << "  HD streaming: Included\n";
        cout << "  4K Ultra HD : " << (ultraHDEnabled ? "Yes" : "No") << "\n";
        cout << "  Renews on   : " << renewalDate        << "\n";
        cout << "  Saved titles: " << downloadedTitles.size() << " downloaded\n";
        cout << "  --------------------------------\n";
    }

    void showWelcome() const override {
        cout << "Good to see you again, " << getName() << "! Your " << plan << " plan is active and ready to go.\n";
        if (ultraHDEnabled) cout << "Your screen supports 4K Ultra HD - enjoy the best picture quality available!\n";
    }
};

class Rating {
private:
    int    contentID;
    int    userID;
    double score;
    string reviewText;
    string datePosted;

public:
    Rating(int cid, int uid, double s,
           const string& r, const string& d)
        : contentID(cid), userID(uid),
          reviewText(r), datePosted(d) {
        setScore(s);
    }

    int    getContentID()  const { return contentID;  }
    int    getUserID()     const { return userID;     }
    double getScore()      const { return score;      }
    string getReview()     const { return reviewText; }
    string getDatePosted() const { return datePosted; }

    void setScore(double s) {
        score = (s < 1.0) ? 1.0 : (s > 5.0) ? 5.0 : s;
    }

    bool   operator>(const Rating& o)  const { return score > o.score;  }
    bool   operator<(const Rating& o)  const { return score < o.score;  }
    bool   operator==(const Rating& o) const { return score == o.score; }
    Rating operator+(const Rating& o)  const {
        return Rating(contentID, 0, (score+o.score)/2.0,
                      "Averaged rating", datePosted);
    }

    friend ostream& operator<<(ostream& os, const Rating& r) {
        os << "Rating[Content#" << r.contentID
           << " User#" << r.userID
           << " Score:" << r.score << "/5"
           << " \"" << r.reviewText << "\"]";
        return os;
    }

    void display() const {
        cout << "  Score: " << score << "/5"
             << " | User#" << userID
             << " | " << datePosted << "\n"
             << "  \"" << reviewText << "\"\n";
    }

    void displayStars() const {
        cout << "  [";
        for (int i=0; i<(int)score; i++)    cout << "*";
        for (int i=(int)score; i<5; i++) cout << "-";
        cout << "] " << score << "/5\n";
    }
};

template<typename T>
class WatchHistory {
private:
    vector<T> history;
    int       maxSize;
    string    ownerName;

public:
    WatchHistory(const string& owner, int max = 50)
        : ownerName(owner), maxSize(max) {}

    void add(const T& content) {
        if ((int)history.size() >= maxSize)
            history.erase(history.begin());
        history.push_back(content);
        cout << "Added to history: \"" << content.getTitle()
             << "\" - watched by " << ownerName << "\n";
    }

    bool hasWatched(int id) const {
        for (const auto& item : history)
            if (item.getContentID() == id) return true;
        return false;
    }

    double totalWatchTime() const {
        double t = 0;
        for (const auto& item : history) t += item.getDuration();
        return t;
    }

    void display() const {
        cout << "\n  Watch history for " << ownerName << ":\n";
        if (history.empty()) { cout << "  Empty.\n"; return; }
        for (int i=0; i<(int)history.size(); i++)
            cout << "  " << i+1 << ". [" << history[i].getContentType() << "] "
                 << history[i].getTitle()
                 << " (" << history[i].getDuration() << "m)\n";
        cout << "  Total time watched: " << totalWatchTime() << " minutes\n";
    }
};

struct MonthlyPlan {
    string name = "Monthly"; double price = 14.99; int days = 30;
    string info() const { return "Monthly ($14.99/month)"; }
};
struct AnnualPlan {
    string name = "Annual"; double price = 119.99; int days = 365;
    string info() const { return "Annual ($119.99/year - 2 months free)"; }
};
struct FamilyPlan {
    string name = "Family"; double price = 22.99;
    int days = 30; int members = 6;
    string info() const { return "Family ($22.99/month, 6 members)"; }
};

template<typename T = MonthlyPlan>
class Subscription {
private:
    T      plan;
    bool   active;
    int    daysLeft;
    string userEmail;
    int    renewals;

public:
    Subscription(const string& email, const T& p, int d)
        : userEmail(email), plan(p), active(true),
          daysLeft(d), renewals(0) {}

    bool   isActive()    const { return active;    }
    int    getDaysLeft() const { return daysLeft;  }
    string getEmail()    const { return userEmail; }
    T      getPlan()     const { return plan;      }

    void renew() {
        daysLeft += plan.days; renewals++;
        if (!active) active = true;
        cout << "Your subscription has been renewed. " << daysLeft << " days left on your plan.\n";
    }
    void cancel() {
        active = false;
        cout << "Subscription cancelled. No worries - you still have access until it runs out.\n";
    }

    void display() const {
        cout << "  Your Subscription\n";
        cout << "  Account     : " << userEmail        << "\n";
        cout << "  Plan        : " << plan.info()      << "\n";
        cout << "  Status      : " << (active ? "Active" : "Inactive") << "\n";
        cout << "  Days left   : " << daysLeft          << " remaining\n";
        cout << "  Times renewed: " << renewals          << " times\n";
        cout << "  ------------------\n";
    }
};

class SDStream : public StreamingEngine {
    int bitrate; bool buffering;
public:
    SDStream(const string& r = "Asia-South")
        : StreamingEngine(r, 2), bitrate(1500), buffering(false) {}
    string getQuality() const override { return "SD (480p)";  }
    int    getBitrate() const override { return bitrate;       }
    void stream() const override {
        cout << "Streaming in standard definition (480p) at " << bitrate
             << " kbps. You may see a few ads. Server: " << getServerRegion() << "\n";
    }
    void adjustBandwidth(int k) override {
        if      (k < 500)  { bitrate=400;  buffering=true;  cout<<"Your connection seems slow - we've dropped the quality to 400 kbps to keep things running. Expect some buffering.\n"; }
        else if (k < 1000) { bitrate=800;  buffering=false; cout<<"Connection looks decent - streaming at 800 kbps.\n"; }
        else               { bitrate=1500; buffering=false; cout<<"Nice connection! Running at full SD quality (1500 kbps).\n"; }
    }
};

class HDStream : public StreamingEngine {
    int bitrate, res;
public:
    HDStream(const string& r = "Asia-South")
        : StreamingEngine(r, 8), bitrate(5000), res(1080) {}
    string getQuality() const override {
        return (res==1080) ? "HD (1080p)" : "HD (720p)";
    }
    int getBitrate() const override { return bitrate; }
    void stream() const override {
        cout << "Streaming in high definition (" << res << "p) at " << bitrate
             << " kbps - completely ad-free. Server: " << getServerRegion() << "\n";
    }
    void adjustBandwidth(int k) override {
        if      (k < 1500) { bitrate=1200; res=720;  cout<<"Bandwidth is a little tight - scaling down to 720p for now.\n"; }
        else if (k < 6000) { bitrate=5000; res=1080; cout<<"Solid connection - streaming at full 1080p.\n"; }
        else               { bitrate=8000; res=1080; cout<<"Great connection! Pushing to maximum HD quality.\n"; }
    }
};

class UltraHDStream : public StreamingEngine {
    int bitrate; bool hdr, atmos;
public:
    UltraHDStream(const string& r = "Asia-South")
        : StreamingEngine(r, 25), bitrate(15000),
          hdr(true), atmos(true) {}
    string getQuality() const override {
        return string("4K (2160p)") + (hdr?"+HDR":"") + (atmos?"+Atmos":"");
    }
    int getBitrate() const override { return bitrate; }
    void stream() const override {
        cout << "Streaming in stunning 4K (2160p) at " << bitrate
             << " kbps - HDR: " << (hdr?"On":"Off")
             << ", Dolby Atmos: " << (atmos?"On":"Off")
             << ", ad-free.\n";
    }
    void adjustBandwidth(int k) override {
        if      (k < 5000)  { bitrate=4000;  hdr=false; cout<<"Not quite enough bandwidth for HDR - turning it off until things improve.\n"; }
        else if (k < 20000) { bitrate=15000; hdr=true;  cout<<"Bandwidth is good - Dolby Vision is switched on.\n"; }
        else                { bitrate=25000; hdr=true; atmos=true; cout<<"Your connection is excellent - full 4K with Dolby Vision and Atmos. Enjoy!\n"; }
    }
};

class DynamicArray {
private:
    int* data;
    int  size_;
    int  capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i=0; i<size_; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    DynamicArray(int cap = 4) : size_(0), capacity(cap) {
        data = new int[capacity];
    }

    DynamicArray(const DynamicArray& other)
        : size_(other.size_), capacity(other.capacity) {
        data = new int[capacity];
        for (int i=0; i<size_; i++) data[i] = other.data[i];
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this; 
        delete[] data;
        size_ = other.size_; capacity = other.capacity;
        data = new int[capacity];
        for (int i=0; i<size_; i++) data[i] = other.data[i];
        return *this;
    }

    ~DynamicArray() { delete[] data; }

    void push(int v) { if (size_==capacity) resize(); data[size_++]=v; }
    void pop()       { if (size_>0) size_--;  }
    int  get(int i)  const { return data[i]; }
    int& operator[](int i) { return data[i]; }
    int  getSize()   const { return size_;   }
    bool isEmpty()   const { return size_==0;}

    void display() const {
        cout << "Array contents: [";
        for (int i=0; i<size_; i++) {
            cout << data[i];
            if (i < size_-1) cout << ",";
        }
        cout << "] size=" << size_ << " cap=" << capacity << "\n";
    }
};

class Stack {
private:
    DynamicArray arr;
    string       name;
public:
    Stack(const string& n = "Stack") : arr(8), name(n) {}

    void push(int v) {
        arr.push(v);
        cout << "Stack [" << name << "]: pushed " << v << "\n";
    }
    int pop() {
        if (arr.isEmpty())
            throw underflow_error("Stack underflow: " + name + " is empty.");
        int top = arr[arr.getSize()-1];
        arr.pop();
        cout << "Stack [" << name << "]: popped " << top << "\n";
        return top;
    }
    int  peek()    const { return arr.get(arr.getSize()-1); }
    bool isEmpty() const { return arr.isEmpty();            }
    int  size()    const { return arr.getSize();            }

    void display() const {
        cout << "Stack [" << name << "]: top -> [";
        for (int i=arr.getSize()-1; i>=0; i--) {
            cout << arr.get(i);
            if (i > 0) cout << ",";
        }
        cout << "]\n";
    }
};

class Queue {
private:
    DynamicArray arr;
    int          front_;
    string       name;
public:
    Queue(const string& n = "Queue") : arr(8), front_(0), name(n) {}

    void enqueue(int v) {
        arr.push(v);
        cout << "Queue [" << name << "]: added " << v << "\n";
    }
    int dequeue() {
        if (isEmpty())
            throw underflow_error("Queue underflow: " + name + " is empty.");
        int val = arr.get(front_++);
        cout << "Queue [" << name << "]: removed " << val << "\n";
        return val;
    }
    int  peek()    const { return arr.get(front_);          }
    bool isEmpty() const { return front_ >= arr.getSize();  }
    int  size()    const { return arr.getSize() - front_;   }

    void display() const {
        cout << "Queue [" << name << "]: front -> [";
        for (int i=front_; i<arr.getSize(); i++) {
            cout << arr.get(i);
            if (i < arr.getSize()-1) cout << ",";
        }
        cout << "] <- rear\n";
    }
};

class ContentCatalog {
private:
    map<int,string>     catalog;      
    std::queue<string>  watchQueue;   
    std::stack<string>  recentStack;  

public:
    void addContent(int id, const string& title) {
        catalog[id] = title;
        cout << "Added \"" << title << "\" to the catalog (ID: " << id << ").\n";
    }
    string findByID(int id) const {
        auto it = catalog.find(id);
        return (it != catalog.end()) ? it->second : "Not found";
    }
    void addToWatchQueue(const string& t) {
        watchQueue.push(t);
        cout << "Added to your watch queue: " << t << "\n";
    }
    void watchNext() {
        if (watchQueue.empty()) { cout << "Your watch queue is empty.\n"; return; }
        string next = watchQueue.front();
        watchQueue.pop(); recentStack.push(next);
        cout << "Starting now: " << next << "\n";
    }
    void showRecent() const {
        std::stack<string> tmp = recentStack;
        cout << "Your recently watched titles (newest first):\n";
        int i = 1;
        while (!tmp.empty()) {
            cout << "  " << i++ << ". " << tmp.top() << "\n";
            tmp.pop();
        }
    }
    void showAll() const {
        cout << "Here's everything currently in the catalog (" << catalog.size() << " titles):\n";
        for (const auto& p : catalog)
            cout << "  [" << p.first << "] " << p.second << "\n";
    }
};

class SearchHelper {
public:
    static void search(const string& keyword) {
        cout << "Searching for: \"" << keyword << "\"\n"; }
    static void search(int contentID) {
        cout << "Looking up content with ID " << contentID << "\n"; }
    static void search(const string& keyword, int year) {
        cout << "Searching: \"" << keyword << "\" from year " << year << "\n"; }
    static void search(double minRating) {
        cout << "Filtering by minimum rating: " << minRating << "+\n"; }
};

class AuthException : public exception {
    string msg;
public:
    AuthException(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class StreamException : public exception {
    string msg;
public:
    StreamException(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class FileException : public exception {
    string msg;
public:
    FileException(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class FileManager {
private:
    const string MOVIES_FILE = "movies.txt";
    const string DOCS_FILE   = "documentaries.txt";
    const string RATINGS_FILE= "ratings.txt";
    const string USERS_FILE  = "users.txt";

    vector<string> splitLine(const string& line, char d='|') const {
        vector<string> tokens;
        stringstream ss(line); string s;
        while (getline(ss, s, d)) tokens.push_back(s);
        return tokens;
    }
    bool fileExists(const string& f) const {
        ifstream fs(f); return fs.good();
    }

public:
    void saveMovies(const vector<Movie>& movies) const {
        ofstream file(MOVIES_FILE);
        if (!file.is_open()) { cerr << "Hmm, couldn't open the movies file. Check if you have write permissions.\n"; return; }
        for (const auto& m : movies)
            file << m.getContentID() << "|" << m.getTitle() << "|"
                 << m.getLanguage()  << "|" << m.getImdbRating() << "|"
                 << m.getReleaseYear()<< "|" << m.getGenre() << "|"
                 << m.getDuration()  << "|" << m.getDirector() << "|"
                 << m.getAgeRating() << "\n";
        file.close();
        cout << movies.size() << " movies saved successfully.\n";
    }

    void saveDocumentaries(const vector<Documentary>& docs) const {
        ofstream file(DOCS_FILE);
        if (!file.is_open()) { cerr << "Hmm, couldn't open the documentaries file. Something might be wrong with the path.\n"; return; }
        for (const auto& d : docs)
            file << d.getContentID()       << "|" << d.getTitle()          << "|"
                 << d.getLanguage()        << "|" << d.getImdbRating()     << "|"
                 << d.getReleaseYear()     << "|" << d.getTopic()          << "|"
                 << d.getNarrator()        << "|" << d.getProductionHouse()<< "|"
                 << d.getDuration()        << "|" << d.getHasSubtitles()   << "\n";
        file.close();
        cout << docs.size() << " documentaries saved successfully.\n";
    }

    void saveUsers(const vector<FreeUser>& fu,
                   const vector<PremiumUser>& pu) const {
        ofstream file(USERS_FILE);
        if (!file.is_open()) return;
        for (const auto& u : fu)
            file << "FREE|" << u.getUserID() << "|"
                 << u.getName() << "|" << u.getEmail() << "|hidden\n";
        for (const auto& u : pu)
            file << "PREMIUM|" << u.getUserID() << "|"
                 << u.getName() << "|" << u.getEmail()
                 << "|hidden|" << u.getPlan() << "\n";
        cout << "Your account data has been saved.\n";
    }

    void appendRating(const Rating& r) const {
        ofstream file(RATINGS_FILE, ios::app);
        if (!file.is_open()) return;
        file << r.getContentID() << "|" << r.getUserID() << "|"
             << r.getScore()     << "|" << r.getReview() << "|"
             << r.getDatePosted()<< "\n";
        cout << "Got it - your rating has been saved!\n";
    }

    vector<Movie> loadMovies() const {
        vector<Movie> mv; ifstream file(MOVIES_FILE);
        if (!file.is_open()) {
            cout << "Couldn't find any saved movies - starting with a clean slate.\n";
            return mv;
        }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if ((int)t.size() < 9) continue;
            try { mv.push_back(Movie(stoi(t[0]),t[1],t[2],stod(t[3]),
                                     stoi(t[4]),t[5],stod(t[6]),t[7],t[8])); }
            catch (...) { cerr << "Found a corrupted entry in the file - skipping it and moving on.\n"; }
        }
        file.close();
        cout << mv.size() << " movies found and loaded.\n";
        return mv;
    }

    vector<Documentary> loadDocumentaries() const {
        vector<Documentary> dv; ifstream file(DOCS_FILE);
        if (!file.is_open()) {
            cout << "No saved documentaries on file - beginning fresh.\n";
            return dv;
        }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if ((int)t.size() < 10) continue;
            try { dv.push_back(Documentary(stoi(t[0]),t[1],t[2],stod(t[3]),
                                            stoi(t[4]),t[5],t[6],t[7],
                                            stod(t[8]),stoi(t[9]))); }
            catch (...) {}
        }
        file.close();
        cout << dv.size() << " documentaries found and loaded.\n";
        return dv;
    }

    vector<Rating> loadRatings() const {
        vector<Rating> rv; ifstream file(RATINGS_FILE);
        if (!file.is_open()) return rv;
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if ((int)t.size() < 5) continue;
            try { rv.push_back(Rating(stoi(t[0]),stoi(t[1]),
                                      stod(t[2]),t[3],t[4])); }
            catch (...) {}
        }
        file.close();
        cout << rv.size() << " user ratings brought back from last session.\n";
        return rv;
    }

    void checkFiles() const {
        cout << "\n  Checking which data files are present on disk...\n";
        for (const auto& f : {MOVIES_FILE,DOCS_FILE,RATINGS_FILE,USERS_FILE})
            cout << "  " << (fileExists(f) ? "  Found:   " : "  Missing: ") << f << "\n";
        cout << "  --------------------------------\n";
    }
};

class Platform;
class Analytics { public: static void showReport(const Platform& p); };

class AdminUser : public User, public StreamingEngine {
private:
    string     adminLevel;
    int        currentBitrate;
    static int adminCount;        

public:
    AdminUser(int id, const string& n, const string& e,
              const string& p, const string& level)
        : User(id, n, e, p),
          StreamingEngine("Admin-Server", 50),
          adminLevel(level), currentBitrate(50000) {
        adminCount++;
        cout << "New admin account set up for " << n
             << " - access level: " << level << ")\n";
    }
    ~AdminUser() { adminCount--; }

    static int getAdminCount() { return adminCount; }

    string getAdminLevel() const { return adminLevel; }

    string getAccountType() const override { return "Admin(" + adminLevel + ")"; }
    bool   canDownload()    const override { return true; }
    bool   canWatchHD()     const override { return true; }
    int    getScreenLimit() const override { return 999;  }

    void displayProfile() const override {
        cout << "\n  ---- Admin Profile ----\n";
        cout << "  Name        : " << getName()         << "\n";
        cout << "  Admin level : " << adminLevel        << "\n";
        cout << "  Server      : " << getServerRegion() << "\n";
        cout << "  Buffer size : " << getBufferSize()   << "MB\n";
        cout << "  ----------------------\n";
    }
    void showWelcome() const override {
        cout << "Welcome, " << getName()
             << "! Admin level: " << adminLevel << "\n";
    }

    string getQuality()  const override { return "Unrestricted (Admin)"; }
    int    getBitrate()  const override { return currentBitrate;         }
    void stream()        const override {
        cout << "Admin mode - streaming at full, unrestricted quality: "
             << currentBitrate << " kbps.\n";
    }
    void adjustBandwidth(int k) override {
        currentBitrate = k;
        cout << "Bandwidth manually overridden to " << k << " kbps by admin.\n";
    }

    void banUser(int id) const {
        cout << "User #" << id << " has been removed from the platform by " << getName() << ".\n";
    }
    void addContent(const string& title) const {
        cout << "\"" << title << "\""  << " is now live in the catalog, added by " << getName() << ".\n";
    }
};
int AdminUser::adminCount = 0;

class Platform {
    friend class Analytics;          

    static int totalUsers;

private:
    vector<Movie>       movies;
    vector<Series>      series;
    vector<Documentary> docs;
    vector<Rating>      ratings;
    vector<FreeUser>    freeUsers;
    vector<PremiumUser> premUsers;

    SDStream      sdEngine;
    HDStream      hdEngine;
    UltraHDStream uhdEngine;
    FileManager   fm;

    User* currentUser;
    bool  loggedIn;

    WatchHistory<Movie>       movieHist;
    WatchHistory<Documentary> docHist;
    int nextID;

    StreamingEngine* selectEngine() {
        if (!currentUser) return &sdEngine;
        string t = currentUser->getAccountType();
        if (t.find("Ultra")   != string::npos) return &uhdEngine;
        if (t.find("Premium") != string::npos) return &hdEngine;
        return &sdEngine;
    }

    Movie*       findMovie(int id) {
        for (auto& m : movies) if (m.getContentID()==id) return &m;
        return nullptr;
    }
    Documentary* findDoc(int id) {
        for (auto& d : docs) if (d.getContentID()==id) return &d;
        return nullptr;
    }
    bool emailExists(const string& e) const {
        for (const auto& u : freeUsers) if (u.getEmail()==e) return true;
        for (const auto& u : premUsers) if (u.getEmail()==e) return true;
        return false;
    }
    void line(char c='-', int n=45) const { cout << string(n,c) << "\n"; }

public:
    Platform() : currentUser(nullptr), loggedIn(false),
                 movieHist("Guest"), docHist("Guest"), nextID(100) {
        cout << "\nWelcome to CineStream! Getting things ready for you...\n";
        movies  = fm.loadMovies();
        docs    = fm.loadDocumentaries();
        ratings = fm.loadRatings();
        seedCatalog();
        cout << "You're all set. Have fun exploring!\n";
    }

    ~Platform() {
        cout << "\nJust a moment, saving everything before we wrap up...\n";
        fm.saveMovies(movies);
        fm.saveDocumentaries(docs);
        fm.saveUsers(freeUsers, premUsers);
        cout << "Hope you enjoyed your time here. Come back soon!\n";
    }

    void seedCatalog() {
        if (!movies.empty() || !docs.empty()) return;
        cout << "Looks like your first time here - filling the catalog with some great picks...\n";
        movies.push_back(Movie(1,"Inception",    "English",8.8,2010,"Sci-Fi",  148,"C. Nolan","PG-13"));
        movies.push_back(Movie(2,"Dark Knight",  "English",9.0,2008,"Action",  152,"C. Nolan","PG-13"));
        movies.push_back(Movie(3,"Parasite",     "Korean", 8.5,2019,"Thriller",132,"B. Joon", "R"    ));
        movies.push_back(Movie(4,"Interstellar", "English",8.6,2014,"Sci-Fi",  169,"C. Nolan","PG-13"));
        movies.push_back(Movie(5,"The Godfather","English",9.2,1972,"Crime",   175,"Coppola", "R"    ));

        Series bb(6,"Breaking Bad","English",9.5,2008,"Drama",5,"Completed");
        bb.addEpisode(Episode(61,"Pilot","English",8.9,2008,1,1,58,"Walt's transformation begins."));
        bb.addEpisode(Episode(62,"Cat's in the Bag","English",8.7,2008,1,2,48,"Cleaning up the mess."));
        series.push_back(bb);

        docs.push_back(Documentary(10,"Planet Earth II",  "English",9.5,2016,"Nature","D. Attenborough","BBC",    360,true));
        docs.push_back(Documentary(11,"Making a Murderer","English",8.6,2015,"Crime", "Various",         "Netflix",600,true));
    }

    static int getTotalUsers() { return totalUsers; }

    bool registerFree(const string& n, const string& e,
                      const string& p) {
        if (emailExists(e)) { cout<<"Looks like that email is already registered. Try logging in instead.\n"; return false; }
        freeUsers.push_back(FreeUser(nextID++, n, e, p));
        totalUsers++;
        cout << "Great news - your account has been created, " << n
             << "! You're user number " << totalUsers << "\n";
        return true;
    }

    bool registerPremium(const string& n, const string& e,
                         const string& p, const string& plan) {
        if (emailExists(e)) { cout<<"Looks like that email is already registered. Try logging in instead.\n"; return false; }
        premUsers.push_back(PremiumUser(nextID++, n, e, p, plan));
        totalUsers++;
        cout << "A Premium account (" << plan << " plan) has been set up for " << n
             << "! You're user number " << totalUsers << "\n";
        return true;
    }

    bool login(const string& e, const string& p) {
        for (auto& u : freeUsers)
            if (u.getEmail()==e && u.checkPassword(p)) {
                currentUser=&u; loggedIn=true;
                movieHist=WatchHistory<Movie>(u.getName());
                docHist=WatchHistory<Documentary>(u.getName());
                u.showWelcome(); return true;
            }
        for (auto& u : premUsers)
            if (u.getEmail()==e && u.checkPassword(p)) {
                currentUser=&u; loggedIn=true;
                movieHist=WatchHistory<Movie>(u.getName());
                docHist=WatchHistory<Documentary>(u.getName());
                u.showWelcome(); return true;
            }
        cout << "That email and password combination didn't match. Give it another shot.\n";
        return false;
    }

    void logout() {
        if (!loggedIn) { cout << "You're not signed in right now.\n"; return; }
        cout << "You've been signed out. Take care, " << currentUser->getName() << "!\n";
        currentUser=nullptr; loggedIn=false;
    }

    void browseCatalog() const {
        line('=');
        cout << "  Movies in the catalog (" << movies.size() << " total)\n"; line('=');
        for (const auto& m : movies) m.display();
        line('-');
        cout << "  TV Series available (" << series.size() << " total)\n"; line('-');
        for (const auto& s : series) s.display();
        line('-');
        cout << "  Documentaries (" << docs.size() << " total)\n"; line('-');
        for (const auto& d : docs) d.display();
        line('=');
    }

    void searchContent(const string& kw) const {
        cout << "\nSearch results for \"" << kw << "\":\n";
        bool found = false;
        for (const auto& m : movies)
            if (m.getTitle().find(kw) != string::npos) {
                cout << "Movie:         " << m.getTitle()
                     << " | IMDB:" << m.getImdbRating() << "\n";
                found = true;
            }
        for (const auto& d : docs)
            if (d.getTitle().find(kw) != string::npos) {
                cout << "Documentary:   " << d.getTitle()
                     << " | IMDB:" << d.getImdbRating() << "\n";
                found = true;
            }
        if (!found) cout << "Nothing came up for that search. Try a different keyword?\n";
    }

    void watchMovie(int id) {
        if (!loggedIn) { cout << "You'll need to sign in first before doing that.\n"; return; }
        Movie* m = findMovie(id);
        if (!m) { cout << "We couldn't find a movie with that ID. Double-check and try again.\n"; return; }
        StreamingEngine* engine = selectEngine();  
        line('=');
        m->play();
        engine->stream();
        engine->showStreamInfo();
        line('=');
        movieHist.add(*m);
        if (currentUser->getAccountType() == "Free")
            if (auto* fu = dynamic_cast<FreeUser*>(currentUser))
                fu->watchContent((int)m->getDuration());
    }

    void watchDoc(int id) {
        if (!loggedIn) { cout << "You'll need to sign in first before doing that.\n"; return; }
        Documentary* d = findDoc(id);
        if (!d) { cout << "That documentary ID doesn't seem to exist. Try browsing the catalog first.\n"; return; }
        line('='); d->play(); selectEngine()->stream(); line('=');
        docHist.add(*d);
    }

    void rateContent(int cid, double score, const string& review) {
        if (!loggedIn) { cout << "You'll need to sign in first before doing that.\n"; return; }
        Rating r(cid, currentUser->getUserID(), score, review, "2025-01-01");
        ratings.push_back(r); fm.appendRating(r);
        cout << "Awesome - thanks for rating! "; r.displayStars();
    }

    void showRatings(int cid) const {
        cout << "\nHere's what people thought about title #" << cid << ":\n";
        bool f = false;
        for (const auto& r : ratings)
            if (r.getContentID()==cid) { r.display(); f=true; }
        if (!f) cout << "Nobody has rated this one yet - be the first!\n";
    }

    void showProfile()  const {
        if (!loggedIn) { cout<<"Sign in to unlock this feature.\n"; return; }
        currentUser->displayProfile();
    }
    void showHistory()  const { movieHist.display(); docHist.display(); }
    void showFiles()    const { fm.checkFiles(); }
    bool isLoggedIn()   const { return loggedIn;     }
    User* getUser()     const { return currentUser;  }
};
int Platform::totalUsers = 0;

void Analytics::showReport(const Platform& p) {
    cout << "\n+========================================+\n";
    cout << "|         ANALYTICS REPORT               |\n";
    cout << "+========================================+\n";
    cout << "| Movies       : " << p.movies.size()    << "\n";
    cout << "| Series       : " << p.series.size()    << "\n";
    cout << "| Documentaries: " << p.docs.size()      << "\n";
    cout << "| Free Users   : " << p.freeUsers.size() << "\n";
    cout << "| Premium Users: " << p.premUsers.size() << "\n";
    cout << "| Total Ratings: " << p.ratings.size()   << "\n";
    if (!p.ratings.empty()) {
        double total = 0;
        const Rating* best = &p.ratings[0];
        for (const auto& r : p.ratings) {
            total += r.getScore();
            if (r > *best) best = &r;
        }
        cout << "| Avg Rating   : " << total/p.ratings.size() << "/5\n";
        cout << "| Best Content : #" << best->getContentID()
             << " (" << best->getScore() << "/5)\n";
    }
    cout << "+========================================+\n";
}

void safeLogin(Platform& p, const string& e, const string& pw) {
    try {
        if (e.empty() || pw.empty())
            throw AuthException("Email and password cannot be empty.");
        if (pw.length() < 4)
            throw AuthException("Password too short (min 4 chars).");
        if (!p.login(e, pw))
            throw AuthException("Invalid credentials for: " + e);
        cout << "You're in! Enjoy your streaming session.\n";
    }
    catch (const AuthException& ex) { cerr << "Oops: " << ex.what() << "\n"; }
    catch (const exception& ex)     { cerr << "Something unexpected happened: " << ex.what() << "\n"; }
}

void safeRegister(Platform& p, const string& n,
                  const string& e, const string& pw) {
    try {
        if (n.empty())                    throw AuthException("Name cannot be empty.");
        if (e.find('@') == string::npos)  throw AuthException("Invalid email: " + e);
        if (pw.length() < 4)              throw AuthException("Password too short.");
        p.registerFree(n, e, pw);
    }
    catch (const AuthException& ex) { cerr << "Could not register: " << ex.what() << "\n"; }
}

void safeWatch(Platform& p, int id) {
    try {
        if (id <= 0)          throw StreamException("Invalid movie ID: " + to_string(id));
        if (!p.isLoggedIn())  throw AuthException("Must be logged in to watch.");
        p.watchMovie(id);
    }
    catch (const AuthException& ex)  { cerr << "Oops: " << ex.what() << "\n"; }
    catch (const StreamException& ex){ cerr << "Streaming issue: " << ex.what() << "\n"; }
}

void clr() { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n'); }

void userMenu(Platform& p) {
    int c;
    while (p.isLoggedIn()) {
        cout << "\n+--------------------------------------+\n";
        cout << "| [1] Browse       [2] Search          |\n";
        cout << "| [3] Watch Movie  [4] Watch Doc       |\n";
        cout << "| [5] Rate         [6] View Ratings    |\n";
        cout << "| [7] History      [8] Profile         |\n";
        cout << "| [9] Files        [0] Logout          |\n";
        cout << "+--------------------------------------+\n";
        cout << "Choice: "; cin >> c;
        if      (c==1) p.browseCatalog();
        else if (c==2) {
            string kw; cout<<"Keyword: "; clr(); getline(cin,kw);
            p.searchContent(kw); }
        else if (c==3) {
            int id; p.browseCatalog();
            cout<<"Movie ID: "; cin>>id; p.watchMovie(id); }
        else if (c==4) {
            int id; p.browseCatalog();
            cout<<"Doc ID: "; cin>>id; p.watchDoc(id); }
        else if (c==5) {
            int id; double s; string r;
            cout<<"Content ID: "; cin>>id;
            cout<<"Score (1-5): "; cin>>s;
            cout<<"Review: "; clr(); getline(cin,r);
            p.rateContent(id,s,r); }
        else if (c==6) {
            int id; cout<<"Content ID: "; cin>>id;
            p.showRatings(id); }
        else if (c==7) p.showHistory();
        else if (c==8) p.showProfile();
        else if (c==9) p.showFiles();
        else if (c==0) p.logout();
        else cout << "That's not a valid option. Please try again.\n";
    }
}

int main() {
    Platform platform;
    int choice;

    while (true) {
        cout << "\n+======================================+\n";
        cout << "|            M-FLIX PLATFORM           |\n";
        cout << "+======================================+\n";
        cout << "|  1. Register (Free Account)          |\n";
        cout << "|  2. Register (Premium Account)       |\n";
        cout << "|  3. Login                            |\n";
        cout << "|  4. Browse Catalog                   |\n";
        cout << "|  0. Exit                             |\n";
        cout << "+======================================+\n";
        cout << "Choice: "; cin >> choice;

        if (choice == 1) {
            string n, e, p;
            cout << "\n-- M-FLIX Free Registration --\n";
            cout << "Name: ";     clr(); getline(cin,n);
            cout << "Email: ";          getline(cin,e);
            cout << "Password: ";       getline(cin,p);
            safeRegister(platform, n, e, p);
        }
        else if (choice == 2) {
            string n, e, p, pl;
            cout << "\n-- M-FlIX Premium Registration --\n";
            cout << "Name: ";                    clr(); getline(cin,n);
            cout << "Email: ";                          getline(cin,e);
            cout << "Password: ";                       getline(cin,p);
            cout << "Plan (Basic/Standard/Ultra): ";    getline(cin,pl);
            if (pl!="Basic"&&pl!="Standard"&&pl!="Ultra") pl="Standard";
            platform.registerPremium(n, e, p, pl);
        }
        else if (choice == 3) {
            string e, p;
            cout << "\n-- M-FLIX Login --\n";
            cout << "Email: ";    clr(); getline(cin,e);
            cout << "Password: ";       getline(cin,p);
            safeLogin(platform, e, p);
            if (platform.isLoggedIn()) userMenu(platform);
        }
        else if (choice == 4) platform.browseCatalog();
        else if (choice == 0) { cout << "Closing M-FLIX. Goodbye!\n"; return 0; }
        else cout << "That's not a valid option. Please try again.\n";
    }
}