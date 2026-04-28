// ============================================================
//  CineStream -> Movie Streaming Platform
//  OOP Concepts Demonstrated:
//    Abstraction -> MediaContent, User, StreamingEngine
//    Inheritance -> Movie/Series/Documentary, FreeUser/PremiumUser
//    Polymorphism -> virtual functions, base pointers
//    Encapsulation -> private data + getters/setters
//    Templates  -> WatchHistory<T>, Subscription<T>
//    File Handling -> ofstream, ifstream, ios::app
// ============================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

// ============================================================
//  STEP 1A: MediaContent â€” Abstract Base Class
// ============================================================
class MediaContent {
private:
    int    contentID;
    string title;
    string language;
    double imdbRating;
    int    releaseYear;

public:
    MediaContent(int id, const string& title, const string& lang,
                 double rating, int year)
        : contentID(id), title(title), language(lang),
          imdbRating(rating), releaseYear(year) {}

    virtual ~MediaContent() {}

    int    getContentID()   const { return contentID;   }
    string getTitle()       const { return title;       }
    string getLanguage()    const { return language;    }
    double getImdbRating()  const { return imdbRating;  }
    int    getReleaseYear() const { return releaseYear; }

    void setTitle(const string& t)   { title = t;      }
    void setLanguage(const string& l){ language = l;   }
    void setImdbRating(double r)     { imdbRating = r; }

    // Pure virtual - makes this class abstract
    virtual void   display()        const = 0;
    virtual string getContentType() const = 0;
    virtual double getDuration()    const = 0;

    virtual void play() const {
        cout << "Playing: " << title << " [" << getContentType() << "]\n";
    }
};

// ============================================================
//  STEP 1B: StreamingEngine â€” Abstract Base Class
// ============================================================
class StreamingEngine {
private:
    string serverRegion;
    int    bufferSizeMB;

public:
    StreamingEngine(const string& region, int buffer)
        : serverRegion(region), bufferSizeMB(buffer) {}

    virtual ~StreamingEngine() {}

    string getServerRegion() const { return serverRegion; }
    int    getBufferSize()   const { return bufferSizeMB; }

    virtual void   stream()                       const = 0;
    virtual string getQuality()                   const = 0;
    virtual int    getBitrate()                   const = 0;
    virtual void   adjustBandwidth(int kbps)            = 0;

    virtual void showStreamInfo() const {
        cout << "Server: " << serverRegion
             << " | Buffer: " << bufferSizeMB << "MB"
             << " | Quality: " << getQuality()
             << " | Bitrate: " << getBitrate() << " kbps\n";
    }
};

// ============================================================
//  STEP 1C: User â€” Abstract Base Class
// ============================================================
class User {
private:
    int    userID;
    string name;
    string email;
    string password;

public:
    User(int id, const string& name, const string& email,
         const string& password)
        : userID(id), name(name), email(email), password(password) {}

    virtual ~User() {}

    int    getUserID() const { return userID; }
    string getName()   const { return name;   }
    string getEmail()  const { return email;  }

    bool checkPassword(const string& pwd) const { return password == pwd; }

    void setName(const string& n)  { name = n;  }
    void setEmail(const string& e) { email = e; }

    virtual string getAccountType() const = 0;
    virtual bool   canDownload()    const = 0;
    virtual bool   canWatchHD()     const = 0;
    virtual int    getScreenLimit() const = 0;
    virtual void   displayProfile() const = 0;

    virtual void showWelcome() const {
        cout << "Welcome, " << name << "! [" << getAccountType() << " Account]\n";
    }
};

// ============================================================
//  STEP 2A: Episode
// ============================================================
class Episode : public MediaContent {
private:
    int    seasonNumber;
    int    episodeNumber;
    double durationMinutes;
    string synopsis;

public:
    Episode(int id, const string& title, const string& lang,
            double imdb, int year, int season, int epNum,
            double duration, const string& synopsis)
        : MediaContent(id, title, lang, imdb, year),
          seasonNumber(season), episodeNumber(epNum),
          durationMinutes(duration), synopsis(synopsis) {}

    int    getSeasonNumber()  const { return seasonNumber;  }
    int    getEpisodeNumber() const { return episodeNumber; }
    string getSynopsis()      const { return synopsis;      }
    void   setSynopsis(const string& s) { synopsis = s; }

    string getContentType() const override { return "Episode"; }
    double getDuration()    const override { return durationMinutes; }

    void display() const override {
        cout << "  [S" << seasonNumber << "E" << episodeNumber << "] "
             << getTitle() << " (" << durationMinutes << " mins)"
             << " - " << synopsis << "\n";
    }

    void play() const override {
        cout << "[EPISODE] Playing S" << seasonNumber
             << "E" << episodeNumber
             << ": \"" << getTitle() << "\"\n";
    }
};

// ============================================================
//  STEP 2B: Movie
// ============================================================
class Movie : public MediaContent {
private:
    string         genre;
    double         durationMinutes;
    string         director;
    string         ageRating;
    vector<string> cast;

public:
    Movie(int id, const string& title, const string& lang,
          double imdb, int year, const string& genre,
          double duration, const string& director,
          const string& ageRating)
        : MediaContent(id, title, lang, imdb, year),
          genre(genre), durationMinutes(duration),
          director(director), ageRating(ageRating) {}

    string getGenre()    const { return genre;    }
    string getDirector() const { return director; }
    string getAgeRating()const { return ageRating;}
    vector<string> getCast() const { return cast; }

    void setGenre(const string& g)          { genre = g; }
    void addCastMember(const string& actor) { cast.push_back(actor); }

    string getContentType() const override { return "Movie"; }
    double getDuration()    const override { return durationMinutes; }

    void display() const override {
        cout << "\n===== MOVIE =====\n";
        cout << "ID       : " << getContentID()   << "\n";
        cout << "Title    : " << getTitle()        << "\n";
        cout << "Genre    : " << genre             << "\n";
        cout << "Director : " << director          << "\n";
        cout << "Duration : " << durationMinutes   << " mins\n";
        cout << "Language : " << getLanguage()     << "\n";
        cout << "IMDB     : " << getImdbRating()   << "/10\n";
        cout << "Year     : " << getReleaseYear()  << "\n";
        cout << "Rating   : " << ageRating         << "\n";
        if (!cast.empty()) {
            cout << "Cast     : ";
            for (const auto& a : cast) cout << a << "  ";
            cout << "\n";
        }
        cout << "=================\n";
    }

    void play() const override {
        cout << "[MOVIE] Now playing: \"" << getTitle()
             << "\" (" << durationMinutes << " mins)\n";
    }
};

// ============================================================
//  STEP 2C: Series
// ============================================================
class Series : public MediaContent {
private:
    string          genre;
    int             totalSeasons;
    string          status;
    vector<Episode> episodes;

public:
    Series(int id, const string& title, const string& lang,
           double imdb, int year, const string& genre,
           int seasons, const string& status)
        : MediaContent(id, title, lang, imdb, year),
          genre(genre), totalSeasons(seasons), status(status) {}

    string getGenre()         const { return genre;            }
    int    getTotalSeasons()  const { return totalSeasons;     }
    string getStatus()        const { return status;           }
    int    getTotalEpisodes() const { return (int)episodes.size(); }

    void addEpisode(const Episode& ep) { episodes.push_back(ep); }

    void playEpisode(int season, int epNum) const {
        for (const auto& ep : episodes)
            if (ep.getSeasonNumber() == season &&
                ep.getEpisodeNumber() == epNum) {
                ep.play(); return;
            }
        cout << "Episode S" << season << "E" << epNum << " not found.\n";
    }

    string getContentType() const override { return "Series"; }

    double getDuration() const override {
        double total = 0;
        for (const auto& ep : episodes) total += ep.getDuration();
        return total;
    }

    void display() const override {
        cout << "\n===== SERIES =====\n";
        cout << "ID       : " << getContentID()    << "\n";
        cout << "Title    : " << getTitle()         << "\n";
        cout << "Genre    : " << genre              << "\n";
        cout << "Seasons  : " << totalSeasons       << "\n";
        cout << "Episodes : " << episodes.size()    << "\n";
        cout << "Status   : " << status             << "\n";
        cout << "Language : " << getLanguage()      << "\n";
        cout << "IMDB     : " << getImdbRating()    << "/10\n";
        cout << "Year     : " << getReleaseYear()   << "\n";
        cout << "------------------\n";
        for (const auto& ep : episodes) ep.display();
        cout << "==================\n";
    }

    void play() const override {
        if (!episodes.empty()) {
            cout << "[SERIES] Auto-playing first episode of \""
                 << getTitle() << "\"\n";
            episodes[0].play();
        } else {
            cout << "[SERIES] No episodes for \"" << getTitle() << "\"\n";
        }
    }
};

// ============================================================
//  STEP 2D: Documentary
// ============================================================
class Documentary : public MediaContent {
private:
    string topic;
    string narrator;
    string productionHouse;
    double durationMinutes;
    bool   hasSubtitles;

public:
    Documentary(int id, const string& title, const string& lang,
                double imdb, int year, const string& topic,
                const string& narrator, const string& production,
                double duration, bool subtitles)
        : MediaContent(id, title, lang, imdb, year),
          topic(topic), narrator(narrator),
          productionHouse(production),
          durationMinutes(duration), hasSubtitles(subtitles) {}

    string getTopic()           const { return topic;           }
    string getNarrator()        const { return narrator;        }
    string getProductionHouse() const { return productionHouse; }
    bool   getHasSubtitles()    const { return hasSubtitles;    }

    void setNarrator(const string& n) { narrator = n;    }
    void setSubtitles(bool s)         { hasSubtitles = s;}

    string getContentType() const override { return "Documentary"; }
    double getDuration()    const override { return durationMinutes; }

    void display() const override {
        cout << "\n===== DOCUMENTARY =====\n";
        cout << "ID         : " << getContentID()    << "\n";
        cout << "Title      : " << getTitle()         << "\n";
        cout << "Topic      : " << topic              << "\n";
        cout << "Narrator   : " << narrator           << "\n";
        cout << "Production : " << productionHouse    << "\n";
        cout << "Duration   : " << durationMinutes    << " mins\n";
        cout << "Language   : " << getLanguage()      << "\n";
        cout << "IMDB       : " << getImdbRating()    << "/10\n";
        cout << "Year       : " << getReleaseYear()   << "\n";
        cout << "Subtitles  : " << (hasSubtitles ? "Yes" : "No") << "\n";
        cout << "=======================\n";
    }

    void play() const override {
        cout << "[DOCUMENTARY] Now streaming: \"" << getTitle()
             << "\" narrated by " << narrator << "\n";
    }
};

// ============================================================
//  STEP 3A: FreeUser
// ============================================================
class FreeUser : public User {
private:
    int  adsWatchedToday;
    int  monthlyWatchLimitMins;
    int  minutesWatchedThisMonth;
    bool isAdSupported;

public:
    FreeUser(int id, const string& name,
             const string& email, const string& password)
        : User(id, name, email, password),
          adsWatchedToday(0), monthlyWatchLimitMins(1800),
          minutesWatchedThisMonth(0), isAdSupported(true) {}

    int getRemainingMinutes() const {
        return monthlyWatchLimitMins - minutesWatchedThisMonth;
    }

    void watchContent(int durationMins) {
        if (minutesWatchedThisMonth + durationMins > monthlyWatchLimitMins) {
            cout << "[FREE] Monthly limit reached! Upgrade to Premium.\n";
            return;
        }
        minutesWatchedThisMonth += durationMins;
        adsWatchedToday++;
        cout << "[AD] Watching a 30-second ad before your content...\n";
        cout << "[FREE] Enjoy! (" << getRemainingMinutes()
             << " mins remaining this month)\n";
    }

    string getAccountType() const override { return "Free"; }
    bool   canDownload()    const override { return false;  }
    bool   canWatchHD()     const override { return false;  }
    int    getScreenLimit() const override { return 1;      }

    void displayProfile() const override {
        cout << "\n===== USER PROFILE =====\n";
        cout << "ID        : " << getUserID()      << "\n";
        cout << "Name      : " << getName()         << "\n";
        cout << "Email     : " << getEmail()        << "\n";
        cout << "Account   : " << getAccountType()  << "\n";
        cout << "Screens   : " << getScreenLimit()  << "\n";
        cout << "Downloads : No\n";
        cout << "HD Access : No\n";
        cout << "Ads       : Yes\n";
        cout << "Watched   : " << minutesWatchedThisMonth
             << " / " << monthlyWatchLimitMins << " mins\n";
        cout << "========================\n";
    }

    void showWelcome() const override {
        cout << "Welcome, " << getName()
             << "! FREE plan â€” " << getRemainingMinutes()
             << " mins remaining this month.\n";
        cout << "Upgrade to Premium for unlimited, ad-free streaming!\n";
    }
};

// ============================================================
//  STEP 3B: PremiumUser
// ============================================================
class PremiumUser : public User {
private:
    string         plan;
    double         monthlyPrice;
    int            screenLimit;
    bool           ultraHDEnabled;
    vector<string> downloadedTitles;
    string         renewalDate;

public:
    PremiumUser(int id, const string& name,
                const string& email, const string& password,
                const string& plan)
        : User(id, name, email, password), plan(plan) {
        if (plan == "Basic") {
            monthlyPrice = 9.99;  screenLimit = 2; ultraHDEnabled = false;
        } else if (plan == "Standard") {
            monthlyPrice = 14.99; screenLimit = 4; ultraHDEnabled = false;
        } else {
            monthlyPrice = 19.99; screenLimit = 6; ultraHDEnabled = true;
        }
        renewalDate = "2025-12-01";
    }

    string getPlan()          const { return plan;         }
    double getMonthlyPrice()  const { return monthlyPrice; }
    bool   isUltraHDEnabled() const { return ultraHDEnabled;}
    string getRenewalDate()   const { return renewalDate;  }
    int    getDownloadCount() const { return (int)downloadedTitles.size(); }

    void downloadTitle(const string& title) {
        downloadedTitles.push_back(title);
        cout << "[PREMIUM] \"" << title << "\" downloaded.\n";
    }

    void showDownloads() const {
        cout << "\n--- Downloads (" << downloadedTitles.size() << ") ---\n";
        for (int i = 0; i < (int)downloadedTitles.size(); i++)
            cout << i+1 << ". " << downloadedTitles[i] << "\n";
    }

    string getAccountType() const override { return "Premium (" + plan + ")"; }
    bool   canDownload()    const override { return true;        }
    bool   canWatchHD()     const override { return true;        }
    int    getScreenLimit() const override { return screenLimit; }

    void displayProfile() const override {
        cout << "\n===== USER PROFILE =====\n";
        cout << "ID        : " << getUserID()       << "\n";
        cout << "Name      : " << getName()          << "\n";
        cout << "Email     : " << getEmail()         << "\n";
        cout << "Account   : " << getAccountType()   << "\n";
        cout << "Plan      : " << plan               << "\n";
        cout << "Price     : $" << monthlyPrice << "/month\n";
        cout << "Screens   : " << screenLimit        << "\n";
        cout << "Downloads : Yes\n";
        cout << "HD Access : Yes\n";
        cout << "Ultra HD  : " << (ultraHDEnabled ? "Yes" : "No") << "\n";
        cout << "Renewal   : " << renewalDate        << "\n";
        cout << "Downloads : " << downloadedTitles.size() << " titles\n";
        cout << "========================\n";
    }

    void showWelcome() const override {
        cout << "Welcome back, " << getName()
             << "! Enjoy unlimited " << plan << " streaming.\n";
        if (ultraHDEnabled)
            cout << "4K Ultra HD is enabled on your account.\n";
    }
};

// ============================================================
//  STEP 4A: Rating (Encapsulation demo)
// ============================================================
class Rating {
private:
    int    contentID;
    int    userID;
    double score;
    string reviewText;
    string datePosted;

public:
    Rating(int contentID, int userID, double score,
           const string& review, const string& date)
        : contentID(contentID), userID(userID),
          reviewText(review), datePosted(date) {
        setScore(score);
    }

    int    getContentID()  const { return contentID;  }
    int    getUserID()     const { return userID;     }
    double getScore()      const { return score;      }
    string getReview()     const { return reviewText; }
    string getDatePosted() const { return datePosted; }

    // Validated setter â€” ENCAPSULATION
    void setScore(double s) {
        if (s < 1.0)      score = 1.0;
        else if (s > 5.0) score = 5.0;
        else              score = s;
    }
    void setReview(const string& r) { reviewText = r; }

    void display() const {
        cout << "  Rating: " << score << "/5.0"
             << " | User #" << userID
             << " | " << datePosted << "\n";
        if (!reviewText.empty())
            cout << "  Review: \"" << reviewText << "\"\n";
    }

    void displayStars() const {
        cout << "  [";
        int full = (int)score;
        for (int i = 0; i < full; i++) cout << "*";
        for (int i = full; i < 5;  i++) cout << "-";
        cout << "] " << score << "/5\n";
    }
};

// ============================================================
//  STEP 4B: WatchHistory<T> â€” Template Class
// ============================================================
template <typename T>
class WatchHistory {
private:
    vector<T> history;
    int       maxHistorySize;
    string    ownerName;

public:
    WatchHistory(const string& owner, int maxSize = 50)
        : ownerName(owner), maxHistorySize(maxSize) {}

    void addToHistory(const T& content) {
        if ((int)history.size() >= maxHistorySize)
            history.erase(history.begin());
        history.push_back(content);
        cout << "[HISTORY] Added \"" << content.getTitle()
             << "\" to " << ownerName << "'s history.\n";
    }

    void removeFromHistory(int contentID) {
        for (auto it = history.begin(); it != history.end(); ++it)
            if (it->getContentID() == contentID) {
                cout << "[HISTORY] Removed \"" << it->getTitle() << "\"\n";
                history.erase(it); return;
            }
        cout << "[HISTORY] ID " << contentID << " not found.\n";
    }

    bool hasWatched(int contentID) const {
        for (const auto& item : history)
            if (item.getContentID() == contentID) return true;
        return false;
    }

    const T* getLastWatched() const {
        if (history.empty()) return nullptr;
        return &history.back();
    }

    void displayHistory() const {
        cout << "\n=== Watch History: " << ownerName << " ===\n";
        if (history.empty()) {
            cout << "No history yet.\n==============================\n";
            return;
        }
        for (int i = 0; i < (int)history.size(); i++)
            cout << i+1 << ". [" << history[i].getContentType() << "] "
                 << history[i].getTitle()
                 << " (" << history[i].getDuration() << " mins)\n";
        cout << "Total: " << history.size() << " titles\n";
        cout << "==============================\n";
    }

    int    getTotalWatched()  const { return (int)history.size(); }
    string getOwnerName()     const { return ownerName;           }

    double getTotalWatchTime() const {
        double total = 0;
        for (const auto& item : history) total += item.getDuration();
        return total;
    }

    void clearHistory() {
        history.clear();
        cout << "[HISTORY] Cleared for " << ownerName << ".\n";
    }
};

// ============================================================
//  STEP 4C: Subscription<T> â€” Template Class + Plan Structs
// ============================================================
struct MonthlyPlan {
    string name = "Monthly"; double price = 14.99; int duration = 30;
    string toString() const { return "Monthly ($" + to_string(price) + "/month)"; }
};

struct AnnualPlan {
    string name = "Annual"; double price = 119.99; int duration = 365;
    string toString() const { return "Annual ($" + to_string(price) + "/year)"; }
};

struct FamilyPlan {
    string name = "Family"; double price = 22.99;
    int duration = 30; int maxMembers = 6;
    string toString() const {
        return "Family ($" + to_string(price) + "/month, " +
               to_string(maxMembers) + " members)";
    }
};

template <typename T = MonthlyPlan>
class Subscription {
private:
    T      plan;
    bool   isActive;
    int    daysRemaining;
    string startDate;
    string userEmail;
    int    renewalCount;

public:
    Subscription(const string& email, const T& plan,
                 const string& startDate, int days)
        : userEmail(email), plan(plan), isActive(true),
          daysRemaining(days), startDate(startDate), renewalCount(0) {}

    bool   getIsActive()      const { return isActive;      }
    int    getDaysRemaining() const { return daysRemaining; }
    string getUserEmail()     const { return userEmail;     }
    T      getPlan()          const { return plan;          }

    void activate() { isActive = true;  cout << "[SUB] Activated.\n"; }
    void cancel()   { isActive = false; cout << "[SUB] Cancelled.\n"; }

    void renew() {
        if (isActive) { daysRemaining += plan.duration; renewalCount++; }
        else          { isActive = true; daysRemaining = plan.duration; renewalCount++; }
        cout << "[SUB] Renewed! " << daysRemaining << " days remaining.\n";
    }

    void displaySubscription() const {
        cout << "\n=== Subscription ===\n";
        cout << "User    : " << userEmail          << "\n";
        cout << "Plan    : " << plan.toString()    << "\n";
        cout << "Status  : " << (isActive ? "Active" : "Inactive") << "\n";
        cout << "Days    : " << daysRemaining       << "\n";
        cout << "Started : " << startDate           << "\n";
        cout << "====================\n";
    }
};

// ============================================================
//  STEP 5A: SDStream
// ============================================================
class SDStream : public StreamingEngine {
private:
    int  currentBitrate;
    int  resolution;
    bool isBuffering;

public:
    SDStream(const string& region = "Asia-South")
        : StreamingEngine(region, 2),
          currentBitrate(1500), resolution(480), isBuffering(false) {}

    string getQuality() const override { return "SD (480p)"; }
    int    getBitrate() const override { return currentBitrate; }

    void stream() const override {
        cout << "\n[SD STREAM] Starting 480p stream...\n";
        cout << "  Resolution : 480p | Bitrate: " << currentBitrate
             << " kbps | Ads: Enabled\n";
        cout << "[SD STREAM] Live.\n";
    }

    void adjustBandwidth(int kbps) override {
        if      (kbps < 500)  { currentBitrate = 400;  isBuffering = true;  cout << "[SD] Low â€” 400 kbps, buffering.\n"; }
        else if (kbps < 1000) { currentBitrate = 800;  isBuffering = false; cout << "[SD] Moderate â€” 800 kbps.\n"; }
        else                  { currentBitrate = 1500; isBuffering = false; cout << "[SD] Good â€” 1500 kbps.\n"; }
    }

    void showStreamInfo() const override {
        cout << "[SD]  480p | " << currentBitrate << " kbps"
             << " | Buffer: " << getBufferSize() << "MB"
             << " | Server: " << getServerRegion() << "\n";
    }
};

// ============================================================
//  STEP 5B: HDStream
// ============================================================
class HDStream : public StreamingEngine {
private:
    int  currentBitrate;
    int  resolution;
    bool adaptiveEnabled;
    bool isBuffering;

public:
    HDStream(const string& region = "Asia-South")
        : StreamingEngine(region, 8),
          currentBitrate(5000), resolution(1080),
          adaptiveEnabled(true), isBuffering(false) {}

    string getQuality() const override {
        return (resolution == 1080) ? "HD (1080p)" : "HD (720p)";
    }
    int getBitrate() const override { return currentBitrate; }

    void stream() const override {
        cout << "\n[HD STREAM] Starting " << resolution << "p stream...\n";
        cout << "  Resolution: " << resolution << "p | Bitrate: "
             << currentBitrate << " kbps | ABR: "
             << (adaptiveEnabled ? "On" : "Off") << " | Ads: None\n";
        cout << "[HD STREAM] Live.\n";
    }

    void adjustBandwidth(int kbps) override {
        if      (kbps < 1500) { currentBitrate = 1200; resolution = 720;  isBuffering = true;  cout << "[HD] Low â€” 720p, buffering.\n"; }
        else if (kbps < 3000) { currentBitrate = 2500; resolution = 720;  isBuffering = false; cout << "[HD] Medium â€” 720p.\n"; }
        else if (kbps < 6000) { currentBitrate = 5000; resolution = 1080; isBuffering = false; cout << "[HD] Good â€” 1080p.\n"; }
        else                  { currentBitrate = 8000; resolution = 1080; isBuffering = false; cout << "[HD] Excellent â€” Max HD.\n"; }
    }

    void showStreamInfo() const override {
        cout << "[HD]  " << resolution << "p | " << currentBitrate << " kbps"
             << " | Buffer: " << getBufferSize() << "MB"
             << " | Server: " << getServerRegion() << "\n";
    }
};

// ============================================================
//  STEP 5C: UltraHDStream
// ============================================================
class UltraHDStream : public StreamingEngine {
private:
    int    currentBitrate;
    bool   hdrEnabled;
    bool   dolbyVisionEnabled;
    bool   dolbyAtmosEnabled;
    string hdrFormat;
    bool   isBuffering;

public:
    UltraHDStream(const string& region = "Asia-South")
        : StreamingEngine(region, 25),
          currentBitrate(15000), hdrEnabled(true),
          dolbyVisionEnabled(true), dolbyAtmosEnabled(true),
          hdrFormat("Dolby Vision"), isBuffering(false) {}

    string getQuality() const override {
        string q = "4K UHD (2160p)";
        if (hdrEnabled)        q += " + " + hdrFormat;
        if (dolbyAtmosEnabled) q += " + Atmos";
        return q;
    }
    int getBitrate() const override { return currentBitrate; }

    void stream() const override {
        cout << "\n[4K STREAM] Starting Ultra HD stream...\n";
        cout << "  Resolution: 2160p | Bitrate: " << currentBitrate
             << " kbps | HDR: " << (hdrEnabled ? hdrFormat : "Off")
             << " | Atmos: " << (dolbyAtmosEnabled ? "On" : "Off")
             << " | Ads: None\n";
        cout << "[4K STREAM] Live. Enjoy cinema quality!\n";
    }

    void adjustBandwidth(int kbps) override {
        if      (kbps < 5000)  { currentBitrate = 4000;  hdrEnabled = false; isBuffering = true;  cout << "[4K] Insufficient â€” dropping HDR.\n"; }
        else if (kbps < 10000) { currentBitrate = 8000;  hdrEnabled = true;  hdrFormat = "HDR10"; isBuffering = false; cout << "[4K] Moderate â€” HDR10.\n"; }
        else if (kbps < 20000) { currentBitrate = 15000; hdrEnabled = true;  hdrFormat = "Dolby Vision"; isBuffering = false; cout << "[4K] Good â€” Dolby Vision.\n"; }
        else                   { currentBitrate = 25000; hdrEnabled = true;  hdrFormat = "Dolby Vision"; dolbyAtmosEnabled = true; isBuffering = false; cout << "[4K] Excellent â€” Max 4K.\n"; }
    }

    void showStreamInfo() const override {
        cout << "[4K]  2160p | " << currentBitrate << " kbps"
             << " | HDR: " << (hdrEnabled ? hdrFormat : "Off")
             << " | Atmos: " << (dolbyAtmosEnabled ? "On" : "Off")
             << " | Server: " << getServerRegion() << "\n";
    }
};

// ============================================================
//  STEP 6: FileManager
// ============================================================
class FileManager {
private:
    const string USERS_FILE         = "users.txt";
    const string MOVIES_FILE        = "movies.txt";
    const string DOCUMENTARIES_FILE = "documentaries.txt";
    const string RATINGS_FILE       = "ratings.txt";
    const string SERIES_FILE        = "series.txt";

    vector<string> splitLine(const string& line, char delim = '|') const {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, delim)) tokens.push_back(token);
        return tokens;
    }

    bool fileExists(const string& filename) const {
        ifstream f(filename);
        return f.good();
    }

public:
    void saveMovies(const vector<Movie>& movies) const {
        ofstream file(MOVIES_FILE);
        if (!file.is_open()) { cerr << "[FILE ERROR] Cannot open " << MOVIES_FILE << "\n"; return; }
        for (const auto& m : movies)
            file << m.getContentID()  << "|" << m.getTitle()      << "|"
                 << m.getLanguage()   << "|" << m.getImdbRating() << "|"
                 << m.getReleaseYear()<< "|" << m.getGenre()      << "|"
                 << m.getDuration()   << "|" << m.getDirector()   << "|"
                 << m.getAgeRating()  << "\n";
        file.close();
        cout << "[FILE] " << movies.size() << " movies saved.\n";
    }

    void saveDocumentaries(const vector<Documentary>& docs) const {
        ofstream file(DOCUMENTARIES_FILE);
        if (!file.is_open()) { cerr << "[FILE ERROR] Cannot open " << DOCUMENTARIES_FILE << "\n"; return; }
        for (const auto& d : docs)
            file << d.getContentID()       << "|" << d.getTitle()          << "|"
                 << d.getLanguage()        << "|" << d.getImdbRating()     << "|"
                 << d.getReleaseYear()     << "|" << d.getTopic()          << "|"
                 << d.getNarrator()        << "|" << d.getProductionHouse()<< "|"
                 << d.getDuration()        << "|" << d.getHasSubtitles()   << "\n";
        file.close();
        cout << "[FILE] " << docs.size() << " documentaries saved.\n";
    }

    void saveUsers(const vector<FreeUser>& freeUsers,
                   const vector<PremiumUser>& premiumUsers) const {
        ofstream file(USERS_FILE);
        if (!file.is_open()) { cerr << "[FILE ERROR] Cannot open " << USERS_FILE << "\n"; return; }
        for (const auto& u : freeUsers)
            file << "FREE|" << u.getUserID() << "|" << u.getName()
                 << "|" << u.getEmail() << "|hidden\n";
        for (const auto& u : premiumUsers)
            file << "PREMIUM|" << u.getUserID() << "|" << u.getName()
                 << "|" << u.getEmail() << "|hidden|" << u.getPlan() << "\n";
        file.close();
        cout << "[FILE] Users saved.\n";
    }

    void saveRatings(const vector<Rating>& ratings) const {
        ofstream file(RATINGS_FILE);
        if (!file.is_open()) { cerr << "[FILE ERROR] Cannot open " << RATINGS_FILE << "\n"; return; }
        for (const auto& r : ratings)
            file << r.getContentID() << "|" << r.getUserID()    << "|"
                 << r.getScore()     << "|" << r.getReview()    << "|"
                 << r.getDatePosted()<< "\n";
        file.close();
        cout << "[FILE] " << ratings.size() << " ratings saved.\n";
    }

    void appendRating(const Rating& r) const {
        ofstream file(RATINGS_FILE, ios::app);
        if (!file.is_open()) { cerr << "[FILE ERROR] Cannot open " << RATINGS_FILE << "\n"; return; }
        file << r.getContentID() << "|" << r.getUserID()    << "|"
             << r.getScore()     << "|" << r.getReview()    << "|"
             << r.getDatePosted()<< "\n";
        file.close();
        cout << "[FILE] Rating appended.\n";
    }

    vector<Movie> loadMovies() const {
        vector<Movie> movies;
        ifstream file(MOVIES_FILE);
        if (!file.is_open()) { cout << "[FILE] movies.txt not found. Starting fresh.\n"; return movies; }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if (t.size() < 9) continue;
            try { movies.push_back(Movie(stoi(t[0]), t[1], t[2], stod(t[3]), stoi(t[4]), t[5], stod(t[6]), t[7], t[8])); }
            catch (...) { cerr << "[FILE] Skipping malformed movie line.\n"; }
        }
        file.close();
        cout << "[FILE] Loaded " << movies.size() << " movies.\n";
        return movies;
    }

    vector<Documentary> loadDocumentaries() const {
        vector<Documentary> docs;
        ifstream file(DOCUMENTARIES_FILE);
        if (!file.is_open()) { cout << "[FILE] documentaries.txt not found. Starting fresh.\n"; return docs; }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if (t.size() < 10) continue;
            try { docs.push_back(Documentary(stoi(t[0]), t[1], t[2], stod(t[3]), stoi(t[4]), t[5], t[6], t[7], stod(t[8]), stoi(t[9]))); }
            catch (...) { cerr << "[FILE] Skipping malformed documentary line.\n"; }
        }
        file.close();
        cout << "[FILE] Loaded " << docs.size() << " documentaries.\n";
        return docs;
    }

    vector<Rating> loadRatings() const {
        vector<Rating> ratings;
        ifstream file(RATINGS_FILE);
        if (!file.is_open()) { cout << "[FILE] ratings.txt not found. Starting fresh.\n"; return ratings; }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            auto t = splitLine(line);
            if (t.size() < 5) continue;
            try { ratings.push_back(Rating(stoi(t[0]), stoi(t[1]), stod(t[2]), t[3], t[4])); }
            catch (...) { cerr << "[FILE] Skipping malformed rating line.\n"; }
        }
        file.close();
        cout << "[FILE] Loaded " << ratings.size() << " ratings.\n";
        return ratings;
    }

    void checkFiles() const {
        cout << "\n=== Data File Status ===\n";
        for (const auto& f : {USERS_FILE, MOVIES_FILE, SERIES_FILE, DOCUMENTARIES_FILE, RATINGS_FILE})
            cout << (fileExists(f) ? "[EXISTS] " : "[MISSING] ") << f << "\n";
        cout << "========================\n";
    }
};

// ============================================================
//  STEP 7A: Platform â€” Central Controller
// ============================================================
class Platform {
private:
    vector<Movie>        movies;
    vector<Series>       seriesList;
    vector<Documentary>  documentaries;
    vector<Rating>       ratings;
    vector<FreeUser>     freeUsers;
    vector<PremiumUser>  premiumUsers;

    SDStream      sdEngine;
    HDStream      hdEngine;
    UltraHDStream uhdEngine;
    FileManager   fileManager;

    User* currentUser;
    bool  isLoggedIn;

    WatchHistory<Movie>       movieHistory;
    WatchHistory<Episode>     episodeHistory;
    WatchHistory<Documentary> docHistory;

    int nextUserID;
    int nextContentID;

    StreamingEngine* selectEngine() {
        if (!currentUser) return &sdEngine;
        string type = currentUser->getAccountType();
        if (type.find("Ultra")   != string::npos) return &uhdEngine;
        if (type.find("Premium") != string::npos) return &hdEngine;
        return &sdEngine;
    }

    Movie*       findMovie(int id)       { for (auto& m : movies)        if (m.getContentID() == id) return &m; return nullptr; }
    Documentary* findDocumentary(int id) { for (auto& d : documentaries) if (d.getContentID() == id) return &d; return nullptr; }

    bool emailExists(const string& email) const {
        for (const auto& u : freeUsers)    if (u.getEmail() == email) return true;
        for (const auto& u : premiumUsers) if (u.getEmail() == email) return true;
        return false;
    }

    void divider(char c = '-', int len = 45) const { cout << string(len, c) << "\n"; }

public:
    Platform()
        : sdEngine("Asia-South"), hdEngine("Asia-South"), uhdEngine("Asia-South"),
          currentUser(nullptr), isLoggedIn(false),
          movieHistory("Guest"), episodeHistory("Guest"), docHistory("Guest"),
          nextUserID(100), nextContentID(200)
    {
        cout << "\n[PLATFORM] Initialising CineStream...\n";
        movies        = fileManager.loadMovies();
        documentaries = fileManager.loadDocumentaries();
        ratings       = fileManager.loadRatings();
        seedCatalogIfEmpty();
        cout << "[PLATFORM] Ready.\n";
    }

    ~Platform() {
        cout << "\n[PLATFORM] Saving data...\n";
        fileManager.saveMovies(movies);
        fileManager.saveDocumentaries(documentaries);
        fileManager.saveUsers(freeUsers, premiumUsers);
        fileManager.saveRatings(ratings);
        cout << "[PLATFORM] Goodbye!\n";
    }

    void seedCatalogIfEmpty() {
        if (!movies.empty() || !documentaries.empty()) return;
        cout << "[PLATFORM] First run. Seeding catalog...\n";
        movies.push_back(Movie(1, "Inception",       "English", 8.8, 2010, "Sci-Fi",   148, "Christopher Nolan",    "PG-13"));
        movies.push_back(Movie(2, "The Dark Knight",  "English", 9.0, 2008, "Action",   152, "Christopher Nolan",    "PG-13"));
        movies.push_back(Movie(3, "Parasite",         "Korean",  8.5, 2019, "Thriller", 132, "Bong Joon-ho",         "R"));
        movies.push_back(Movie(4, "Interstellar",     "English", 8.6, 2014, "Sci-Fi",   169, "Christopher Nolan",    "PG-13"));
        movies.push_back(Movie(5, "The Godfather",    "English", 9.2, 1972, "Crime",    175, "Francis Ford Coppola", "R"));
        documentaries.push_back(Documentary(10, "Planet Earth II",   "English", 9.5, 2016, "Nature", "David Attenborough", "BBC",     360, true));
        documentaries.push_back(Documentary(11, "Making a Murderer", "English", 8.6, 2015, "Crime",  "Various",            "Netflix", 600, true));
        nextContentID = 20;
    }

    bool registerFreeUser(const string& name, const string& email, const string& password) {
        if (emailExists(email)) { cout << "[AUTH] Email already registered.\n"; return false; }
        freeUsers.push_back(FreeUser(nextUserID++, name, email, password));
        cout << "[AUTH] Free account created for " << name << ".\n";
        return true;
    }

    bool registerPremiumUser(const string& name, const string& email,
                             const string& password, const string& plan) {
        if (emailExists(email)) { cout << "[AUTH] Email already registered.\n"; return false; }
        premiumUsers.push_back(PremiumUser(nextUserID++, name, email, password, plan));
        cout << "[AUTH] Premium (" << plan << ") account created for " << name << ".\n";
        return true;
    }

    bool login(const string& email, const string& password) {
        for (auto& u : freeUsers)
            if (u.getEmail() == email && u.checkPassword(password)) {
                currentUser = &u; isLoggedIn = true;
                movieHistory = WatchHistory<Movie>(u.getName());
                episodeHistory = WatchHistory<Episode>(u.getName());
                docHistory = WatchHistory<Documentary>(u.getName());
                u.showWelcome(); return true;
            }
        for (auto& u : premiumUsers)
            if (u.getEmail() == email && u.checkPassword(password)) {
                currentUser = &u; isLoggedIn = true;
                movieHistory = WatchHistory<Movie>(u.getName());
                episodeHistory = WatchHistory<Episode>(u.getName());
                docHistory = WatchHistory<Documentary>(u.getName());
                u.showWelcome(); return true;
            }
        cout << "[AUTH] Invalid email or password.\n";
        return false;
    }

    void logout() {
        if (!isLoggedIn) { cout << "Not logged in.\n"; return; }
        cout << "[AUTH] Goodbye, " << currentUser->getName() << "!\n";
        currentUser = nullptr; isLoggedIn = false;
    }

    void browseCatalog() const {
        divider('=', 45);
        cout << "  MOVIE CATALOG (" << movies.size() << " titles)\n";
        divider('=', 45);
        for (const auto& m : movies)
            cout << "[" << m.getContentID() << "] " << m.getTitle()
                 << " (" << m.getReleaseYear() << ") | " << m.getGenre()
                 << " | IMDB: " << m.getImdbRating()
                 << " | " << m.getDuration() << " mins\n";
        divider('-');
        cout << "  DOCUMENTARY CATALOG (" << documentaries.size() << " titles)\n";
        divider('-');
        for (const auto& d : documentaries)
            cout << "[" << d.getContentID() << "] " << d.getTitle()
                 << " (" << d.getReleaseYear() << ") | " << d.getTopic()
                 << " | IMDB: " << d.getImdbRating()
                 << " | " << d.getDuration() << " mins\n";
        divider('=', 45);
    }

    void searchContent(const string& keyword) const {
        cout << "\n--- Search: \"" << keyword << "\" ---\n";
        bool found = false;
        for (const auto& m : movies)
            if (m.getTitle().find(keyword) != string::npos) {
                cout << "[Movie] " << m.getTitle() << " | IMDB: " << m.getImdbRating() << "\n";
                found = true;
            }
        for (const auto& d : documentaries)
            if (d.getTitle().find(keyword) != string::npos) {
                cout << "[Documentary] " << d.getTitle() << " | IMDB: " << d.getImdbRating() << "\n";
                found = true;
            }
        if (!found) cout << "No results found.\n";
    }

    void watchMovie(int movieID) {
        if (!isLoggedIn) { cout << "Please login first.\n"; return; }
        Movie* m = findMovie(movieID);
        if (!m) { cout << "Movie not found.\n"; return; }
        StreamingEngine* engine = selectEngine();
        divider('=', 45);
        m->play();
        engine->stream();
        engine->showStreamInfo();
        divider('=', 45);
        movieHistory.addToHistory(*m);
        if (currentUser->getAccountType() == "Free") {
            FreeUser* fu = dynamic_cast<FreeUser*>(currentUser);
            if (fu) fu->watchContent((int)m->getDuration());
        }
    }

    void watchDocumentary(int docID) {
        if (!isLoggedIn) { cout << "Please login first.\n"; return; }
        Documentary* d = findDocumentary(docID);
        if (!d) { cout << "Documentary not found.\n"; return; }
        StreamingEngine* engine = selectEngine();
        divider('=', 45);
        d->play();
        engine->stream();
        engine->showStreamInfo();
        divider('=', 45);
        docHistory.addToHistory(*d);
    }

    void rateContent(int contentID, double score, const string& review) {
        if (!isLoggedIn) { cout << "Please login first.\n"; return; }
        Rating r(contentID, currentUser->getUserID(), score, review, "2025-01-01");
        ratings.push_back(r);
        fileManager.appendRating(r);
        cout << "[RATING] Thank you!\n";
        r.displayStars();
    }

    void showRatingsForContent(int contentID) const {
        cout << "\n--- Ratings for Content #" << contentID << " ---\n";
        bool found = false;
        for (const auto& r : ratings)
            if (r.getContentID() == contentID) { r.display(); found = true; }
        if (!found) cout << "No ratings yet.\n";
    }

    void showProfile()      const { if (!isLoggedIn) { cout << "Login first.\n"; return; } currentUser->displayProfile(); }
    void showFileStatus()   const { fileManager.checkFiles(); }
    void showWatchHistory() const {
        movieHistory.displayHistory();
        docHistory.displayHistory();
        cout << "Total watch time: "
             << movieHistory.getTotalWatchTime() + docHistory.getTotalWatchTime()
             << " mins\n";
    }

    bool  getIsLoggedIn()   const { return isLoggedIn;   }
    User* getCurrentUser()  const { return currentUser;  }
};

// ============================================================
//  STEP 7B: main â€” Menu-driven entry point
// ============================================================
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printMainMenu() {
    cout << "\n+======================================+\n";
    cout << "|         CINESTREAM PLATFORM          |\n";
    cout << "+======================================+\n";
    cout << "|  1. Register (Free Account)          |\n";
    cout << "|  2. Register (Premium Account)       |\n";
    cout << "|  3. Login                            |\n";
    cout << "|  4. Browse Catalog (no login needed) |\n";
    cout << "|  0. Exit                             |\n";
    cout << "+======================================+\n";
    cout << "Choice: ";
}

void printUserMenu(const string& name, const string& type) {
    cout << "\n+======================================+\n";
    cout << "|  Logged in: " << name;
    cout << string(max(0, 26 - (int)name.size()), ' ') << "|\n";
    cout << "|  Account  : " << type;
    cout << string(max(0, 26 - (int)type.size()), ' ') << "|\n";
    cout << "+======================================+\n";
    cout << "|  1. Browse Catalog                   |\n";
    cout << "|  2. Search Content                   |\n";
    cout << "|  3. Watch a Movie                    |\n";
    cout << "|  4. Watch a Documentary              |\n";
    cout << "|  5. Rate Content                     |\n";
    cout << "|  6. View Ratings for Content         |\n";
    cout << "|  7. My Watch History                 |\n";
    cout << "|  8. My Profile                       |\n";
    cout << "|  9. File Status                      |\n";
    cout << "|  0. Logout                           |\n";
    cout << "+======================================+\n";
    cout << "Choice: ";
}

void handleUserMenu(Platform& p) {
    int choice;
    while (p.getIsLoggedIn()) {
        printUserMenu(p.getCurrentUser()->getName(),
                      p.getCurrentUser()->getAccountType());
        cin >> choice;
        switch (choice) {
            case 1: p.browseCatalog(); break;
            case 2: { string kw; cout << "Keyword: "; clearInput(); getline(cin, kw); p.searchContent(kw); break; }
            case 3: { int id; p.browseCatalog(); cout << "Movie ID: "; cin >> id; p.watchMovie(id); break; }
            case 4: { int id; p.browseCatalog(); cout << "Documentary ID: "; cin >> id; p.watchDocumentary(id); break; }
            case 5: { int id; double score; string review;
                      cout << "Content ID: "; cin >> id;
                      cout << "Score (1-5): "; cin >> score;
                      cout << "Review: "; clearInput(); getline(cin, review);
                      p.rateContent(id, score, review); break; }
            case 6: { int id; cout << "Content ID: "; cin >> id; p.showRatingsForContent(id); break; }
            case 7: p.showWatchHistory(); break;
            case 8: p.showProfile(); break;
            case 9: p.showFileStatus(); break;
            case 0: p.logout(); break;
            default: cout << "Invalid choice.\n";
        }
    }
}

int main() {
    Platform platform;
    int choice;

    while (true) {
        printMainMenu();
        cin >> choice;
        switch (choice) {
            case 1: {
                string name, email, password;
                cout << "\n-- Free Registration --\n";
                cout << "Name: ";     clearInput(); getline(cin, name);
                cout << "Email: ";    getline(cin, email);
                cout << "Password: "; getline(cin, password);
                platform.registerFreeUser(name, email, password);
                break;
            }
            case 2: {
                string name, email, password, plan;
                cout << "\n-- Premium Registration --\n";
                cout << "Name: ";     clearInput(); getline(cin, name);
                cout << "Email: ";    getline(cin, email);
                cout << "Password: "; getline(cin, password);
                cout << "Plan (Basic/Standard/Ultra): "; getline(cin, plan);
                if (plan != "Basic" && plan != "Standard" && plan != "Ultra") plan = "Standard";
                platform.registerPremiumUser(name, email, password, plan);
                break;
            }
            case 3: {
                string email, password;
                cout << "\n-- Login --\n";
                cout << "Email: ";    clearInput(); getline(cin, email);
                cout << "Password: "; getline(cin, password);
                platform.login(email, password);
                if (platform.getIsLoggedIn()) handleUserMenu(platform);
                break;
            }
            case 4: platform.browseCatalog(); break;
            case 0: cout << "Exiting CineStream...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}