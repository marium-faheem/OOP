#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ============ MEDIA CONTENT HIERARCHY ============

class MediaContent {
protected:
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

    virtual void   display()        const = 0;
    virtual string getContentType() const = 0;
    virtual double getDuration()    const = 0;

    virtual void play() const {
        cout << "Now playing: " << title
             << " [" << getContentType() << "]\n";
    }
};

// Movie class
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

// Episode class
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
        cout << "Now watching - Season " << seasonNo << ", Episode " << episodeNo 
             << ": \"" << getTitle() << "\"\n";
    }
};

// Series class
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

// Documentary class
class Documentary : public MediaContent {
private:
    string topic;
    string narrator;
    double durationMins;

public:
    Documentary(int id, const string& t, const string& l,
                double r, int y, const string& top,
                const string& nar, double d)
        : MediaContent(id, t, l, r, y),
          topic(top), narrator(nar), durationMins(d) {}

    string getTopic()    const { return topic;    }
    string getNarrator() const { return narrator; }

    string getContentType() const override { return "Documentary"; }
    double getDuration()    const override { return durationMins;  }

    void display() const override {
        cout << "\n  ---- Documentary Details ----\n";
        cout << "  ID          : " << getContentID()  << "\n";
        cout << "  Title       : " << getTitle()       << "\n";
        cout << "  Topic       : " << topic            << "\n";
        cout << "  Narrator    : " << narrator         << "\n";
        cout << "  Runtime     : " << durationMins     << " mins\n";
        cout << "  Language    : " << getLanguage()    << "\n";
        cout << "  IMDB rating : " << getImdbRating()  << "/10\n";
        cout << "  Released    : " << getReleaseYear() << "\n";
        cout << "  ----------------------------\n";
    }

    void play() const override {
        cout << "Now streaming: \"" << getTitle() 
             << "\" narrated by " << narrator << "\n";
    }
};

// ============ USER HIERARCHY ============

class User {
protected:
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

    virtual string getAccountType() const = 0;
    virtual bool   canWatchHD()     const = 0;
    virtual void   displayProfile() const = 0;

    virtual void showWelcome() const {
        cout << "Welcome, " << name << "! [" << getAccountType() << "]\n";
    }
};

// Free User
class FreeUser : public User {
private:
    int minutesWatched;
    int monthlyLimit;

public:
    FreeUser(int id, const string& n, const string& e, const string& p)
        : User(id, n, e, p),
          minutesWatched(0), monthlyLimit(1800) {}

    int getRemainingMins() const { return monthlyLimit - minutesWatched; }

    void watchContent(int mins) {
        if (minutesWatched + mins > monthlyLimit) {
            cout << "You've used up all your free minutes for this month. Upgrade to Premium!\n";
            return;
        }
        minutesWatched += mins;
        cout << "Ads playing... You have " << getRemainingMins() << " minutes left.\n";
    }

    string getAccountType() const override { return "Free";  }
    bool   canWatchHD()     const override { return false;   }

    void displayProfile() const override {
        cout << "\n  ---- Your Profile ----\n";
        cout << "  User ID     : " << userID      << "\n";
        cout << "  Name        : " << name         << "\n";
        cout << "  Email       : " << email        << "\n";
        cout << "  Account     : " << getAccountType()  << "\n";
        cout << "  Watch time  : " << minutesWatched << " / " << monthlyLimit << " minutes\n";
        cout << "  HD access   : No\n";
        cout << "  Ads         : Yes\n";
        cout << "  --------------------------------\n";
    }

    void showWelcome() const override {
        cout << "Hey " << name << "! Free plan - " << getRemainingMins() 
             << " minutes left this month.\n";
    }
};

// Premium User
class PremiumUser : public User {
private:
    string plan;
    double monthlyPrice;

public:
    PremiumUser(int id, const string& n, const string& e,
                const string& p, const string& pl)
        : User(id, n, e, p), plan(pl) {
        if (pl == "Basic")   monthlyPrice = 9.99;
        else if (pl == "Standard") monthlyPrice = 14.99;
        else monthlyPrice = 19.99;
    }

    string getPlan()         const { return plan;          }
    double getMonthlyPrice() const { return monthlyPrice;  }

    string getAccountType() const override { return "Premium(" + plan + ")"; }
    bool   canWatchHD()     const override { return true;  }

    void displayProfile() const override {
        cout << "\n  ---- Your Profile ----\n";
        cout << "  User ID     : " << userID      << "\n";
        cout << "  Name        : " << name         << "\n";
        cout << "  Email       : " << email        << "\n";
        cout << "  Account     : " << getAccountType()   << "\n";
        cout << "  Plan        : " << plan         << "\n";
        cout << "  Price       : $" << monthlyPrice << "/month\n";
        cout << "  HD access   : Yes\n";
        cout << "  Ads         : No\n";
        cout << "  --------------------------------\n";
    }

    void showWelcome() const override {
        cout << "Welcome back, " << name << "! Premium (" << plan << ") active.\n";
    }
};

// ============ RATING SYSTEM ============

class Rating {
private:
    int    contentID;
    int    userID;
    double score;
    string reviewText;

public:
    Rating(int cid, int uid, double s, const string& r)
        : contentID(cid), userID(uid), reviewText(r) {
        score = (s < 1.0) ? 1.0 : (s > 5.0) ? 5.0 : s;
    }

    int    getContentID() const { return contentID; }
    int    getUserID()    const { return userID;    }
    double getScore()     const { return score;     }
    string getReview()    const { return reviewText;}

    void display() const {
        cout << "  Score: " << score << "/5 | User#" << userID << "\n"
             << "  \"" << reviewText << "\"\n";
    }

    void displayStars() const {
        cout << "  [";
        for (int i=0; i<(int)score; i++)    cout << "*";
        for (int i=(int)score; i<5; i++) cout << "-";
        cout << "] " << score << "/5\n";
    }
};

// ============ MAIN PLATFORM ============

class Platform {
private:
    vector<Movie>       movies;
    vector<Series>      series;
    vector<Documentary> docs;
    vector<Rating>      ratings;
    vector<FreeUser>    freeUsers;
    vector<PremiumUser> premUsers;

    User* currentUser;
    bool  loggedIn;
    int   nextID;

    Movie* findMovie(int id) {
        for (auto& m : movies) if (m.getContentID()==id) return &m;
        return nullptr;
    }

    Series* findSeries(int id) {
        for (auto& s : series) if (s.getContentID()==id) return &s;
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

    void line(char c='-', int n=45) const { 
        cout << string(n,c) << "\n"; 
    }

public:
    Platform() : currentUser(nullptr), loggedIn(false), nextID(100) {
        cout << "\nWelcome to M-Flix!\n";
        seedCatalog();
        cout << "Ready to go!\n\n";
    }

    void seedCatalog() {
        // Movies
        movies.push_back(Movie(1,"Inception",    "English",8.8,2010,"Sci-Fi",  148,"C. Nolan","PG-13"));
        movies.push_back(Movie(2,"Dark Knight",  "English",9.0,2008,"Action",  152,"C. Nolan","PG-13"));
        movies.push_back(Movie(3,"Parasite",     "Korean", 8.5,2019,"Thriller",132,"B. Joon", "R"    ));

        // Series
        Series bb(4,"Breaking Bad","English",9.5,2008,"Drama",5,"Completed");
        bb.addEpisode(Episode(41,"Pilot","English",8.9,2008,1,1,58,"Walt's transformation begins."));
        bb.addEpisode(Episode(42,"Cat's in the Bag","English",8.7,2008,1,2,48,"Cleaning up."));
        series.push_back(bb);

        Series vd(5,"The Vampire Diaries","English",8.3,2009,"Supernatural",8,"Completed");
        vd.addEpisode(Episode(51,"Pilot","English",8.2,2009,1,1,45,"Elena meets Stefan."));
        vd.addEpisode(Episode(52,"The Night of the Comet","English",8.1,2009,1,2,42,"Dark secrets."));
        series.push_back(vd);

        Series st(6,"Stranger Things","English",8.7,2016,"Sci-Fi Horror",4,"Ongoing");
        st.addEpisode(Episode(61,"Chapter One","English",8.8,2016,1,1,47,"A boy disappears."));
        st.addEpisode(Episode(62,"Chapter Two","English",8.6,2016,1,2,46,"Strange events."));
        series.push_back(st);

        // Documentaries
        docs.push_back(Documentary(7,"Planet Earth II","English",9.5,2016,"Nature","David Attenborough",360));
        docs.push_back(Documentary(8,"Making a Murderer","English",8.6,2015,"Crime","Various",600));
    }

    bool registerFree(const string& n, const string& e, const string& p) {
        if (emailExists(e)) { 
            cout << "Email already registered.\n"; 
            return false; 
        }
        freeUsers.push_back(FreeUser(nextID++, n, e, p));
        cout << "Free account created for " << n << "!\n";
        return true;
    }

    bool registerPremium(const string& n, const string& e, 
                         const string& p, const string& plan) {
        if (emailExists(e)) { 
            cout << "Email already registered.\n"; 
            return false; 
        }
        premUsers.push_back(PremiumUser(nextID++, n, e, p, plan));
        cout << "Premium account (" << plan << ") created for " << n << "!\n";
        return true;
    }

    bool login(const string& e, const string& p) {
        for (auto& u : freeUsers)
            if (u.getEmail()==e && u.checkPassword(p)) {
                currentUser=&u; loggedIn=true;
                u.showWelcome(); 
                return true;
            }
        for (auto& u : premUsers)
            if (u.getEmail()==e && u.checkPassword(p)) {
                currentUser=&u; loggedIn=true;
                u.showWelcome(); 
                return true;
            }
        cout << "Invalid credentials.\n";
        return false;
    }

    void logout() {
        if (!loggedIn) return;
        cout << "Logged out. Goodbye!\n";
        currentUser=nullptr; 
        loggedIn=false;
    }

    void browseCatalog() const {
        line('=');
        cout << "  MOVIES (" << movies.size() << ")\n"; 
        line('=');
        for (const auto& m : movies) m.display();
        
        line('-');
        cout << "  TV SERIES (" << series.size() << ")\n"; 
        line('-');
        for (const auto& s : series) s.display();
        
        line('-');
        cout << "  DOCUMENTARIES (" << docs.size() << ")\n"; 
        line('-');
        for (const auto& d : docs) d.display();
        line('=');
    }

    void searchContent(const string& kw) const {
        cout << "\nSearch: \"" << kw << "\"\n";
        bool found = false;
        for (const auto& m : movies)
            if (m.getTitle().find(kw) != string::npos) {
                cout << "Movie: " << m.getTitle() << " | IMDB:" << m.getImdbRating() << "\n";
                found = true;
            }
        for (const auto& s : series)
            if (s.getTitle().find(kw) != string::npos) {
                cout << "Series: " << s.getTitle() << " | IMDB:" << s.getImdbRating() << "\n";
                found = true;
            }
        for (const auto& d : docs)
            if (d.getTitle().find(kw) != string::npos) {
                cout << "Doc: " << d.getTitle() << " | IMDB:" << d.getImdbRating() << "\n";
                found = true;
            }
        if (!found) cout << "No results found.\n";
    }

    void watchMovie(int id) {
        if (!loggedIn) { cout << "Login first.\n"; return; }
        Movie* m = findMovie(id);
        if (!m) { cout << "Movie not found.\n"; return; }
        
        line('=');
        m->play();
        if (currentUser->canWatchHD()) {
            cout << "Streaming in HD (1080p) - Ad free\n";
        } else {
            cout << "Streaming in SD (480p) - Ads playing\n";
            if (auto* fu = dynamic_cast<FreeUser*>(currentUser))
                fu->watchContent((int)m->getDuration());
        }
        line('=');
    }

    void watchSeries(int id) {
        if (!loggedIn) { cout << "Login first.\n"; return; }
        Series* s = findSeries(id);
        if (!s) { cout << "Series not found.\n"; return; }
        
        line('=');
        s->play();
        cout << "Quality: " << (currentUser->canWatchHD() ? "HD" : "SD") << "\n";
        line('=');
    }

    void watchDoc(int id) {
        if (!loggedIn) { cout << "Login first.\n"; return; }
        Documentary* d = findDoc(id);
        if (!d) { cout << "Documentary not found.\n"; return; }
        
        line('=');
        d->play();
        cout << "Quality: " << (currentUser->canWatchHD() ? "HD" : "SD") << "\n";
        line('=');
    }

    void rateContent(int cid, double score, const string& review) {
        if (!loggedIn) { cout << "Login first.\n"; return; }
        Rating r(cid, currentUser->getUserID(), score, review);
        ratings.push_back(r);
        cout << "Thanks for rating! ";
        r.displayStars();
    }

    void showRatings(int cid) const {
        cout << "\nRatings for content #" << cid << ":\n";
        bool found = false;
        for (const auto& r : ratings)
            if (r.getContentID()==cid) { 
                r.display(); 
                found = true; 
            }
        if (!found) cout << "No ratings yet.\n";
    }

    void showProfile() const {
        if (!loggedIn) { cout << "Login first.\n"; return; }
        currentUser->displayProfile();
    }

    bool isLoggedIn() const { return loggedIn; }
};

// ============ MAIN MENU ============

void clr() { 
    cin.clear(); 
    cin.ignore(10000, '\n'); 
}

void userMenu(Platform& p) {
    int c;
    while (p.isLoggedIn()) {
        cout << "\n+--------------------------------------+\n";
        cout << "|  M-FLIX USER MENU                    |\n";
        cout << "| [1] Browse       [2] Search          |\n";
        cout << "| [3] Watch Movie  [4] Watch Series    |\n";
        cout << "| [5] Watch Doc    [6] Rate Content    |\n";
        cout << "| [7] View Ratings [8] Profile         |\n";
        cout << "| [0] Logout                           |\n";
        cout << "+--------------------------------------+\n";
        cout << "Choice: "; 
        cin >> c;

        if      (c==1) p.browseCatalog();
        else if (c==2) {
            string kw; 
            cout<<"Keyword: "; 
            clr(); 
            getline(cin,kw);
            p.searchContent(kw); 
        }
        else if (c==3) {
            int id; 
            cout<<"Movie ID: "; 
            cin>>id; 
            p.watchMovie(id); 
        }
        else if (c==4) {
            int id; 
            cout<<"Series ID: "; 
            cin>>id; 
            p.watchSeries(id); 
        }
        else if (c==5) {
            int id; 
            cout<<"Doc ID: "; 
            cin>>id; 
            p.watchDoc(id); 
        }
        else if (c==6) {
            int id; 
            double s; 
            string r;
            cout<<"Content ID: "; 
            cin>>id;
            cout<<"Score (1-5): "; 
            cin>>s;
            cout<<"Review: "; 
            clr(); 
            getline(cin,r);
            p.rateContent(id,s,r); 
        }
        else if (c==7) {
            int id; 
            cout<<"Content ID: "; 
            cin>>id;
            p.showRatings(id); 
        }
        else if (c==8) p.showProfile();
        else if (c==0) p.logout();
        else cout << "Invalid choice.\n";
    }
}

int main() {
    Platform platform;
    int choice;

    while (true) {
        cout << "\n+======================================+\n";
        cout << "|         M-FLIX PLATFORM              |\n";
        cout << "|    Your Personal Movie Streaming     |\n";
        cout << "+======================================+\n";
        cout << "|  1. Register (Free)                  |\n";
        cout << "|  2. Register (Premium)               |\n";
        cout << "|  3. Login                            |\n";
        cout << "|  4. Browse Catalog                   |\n";
        cout << "|  0. Exit                             |\n";
        cout << "+======================================+\n";
        cout << "Choice: "; 
        cin >> choice;

        if (choice == 1) {
            string n, e, p;
            cout << "\n-- Free Registration --\n";
            cout << "Name: ";     
            clr(); 
            getline(cin,n);
            cout << "Email: ";          
            getline(cin,e);
            cout << "Password: ";       
            getline(cin,p);
            platform.registerFree(n, e, p);
        }
        else if (choice == 2) {
            string n, e, p, pl;
            cout << "\n-- Premium Registration --\n";
            cout << "Name: ";                    
            clr(); 
            getline(cin,n);
            cout << "Email: ";                          
            getline(cin,e);
            cout << "Password: ";                       
            getline(cin,p);
            cout << "Plan (Basic/Standard/Ultra): ";    
            getline(cin,pl);
            if (pl!="Basic"&&pl!="Standard"&&pl!="Ultra") pl="Standard";
            platform.registerPremium(n, e, p, pl);
        }
        else if (choice == 3) {
            string e, p;
            cout << "\n-- Login --\n";
            cout << "Email: ";    
            clr(); 
            getline(cin,e);
            cout << "Password: ";       
            getline(cin,p);
            if (platform.login(e, p)) {
                userMenu(platform);
            }
        }
        else if (choice == 4) platform.browseCatalog();
        else if (choice == 0) { 
            cout << "Goodbye!\n"; 
            return 0; 
        }
        else cout << "Invalid choice.\n";
    }
}