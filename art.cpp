#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Art {
    protected:
        string artist;
        string title;
        int year;
        string type;
    public:
        Art(string a, string t, int y, string ty) : artist(a), title(t), year(y), type(ty) {}
        Art() {}
        string getArtist() {return artist;}
        string getTitle() {return title;}
        int getYear() {return year;}
        void setAtt(string a, string t, int y, string ty) {
            artist = a;
            title = t;
            year = y;
            type = ty;
        } 
        void display();
};

class VisualArt : public Art {
    public:
        VisualArt(string a, string t, int y, string ty) : Art(a, t, y, ty) {}
        void admire() {cout << "Admiring" << endl;}
};

class Painting : public VisualArt {
    private:
        int size;
    public:
        Painting(string a, string t, int y, string ty, int s) : VisualArt(a, t, y, ty) {size = s;}
        void showCasePaintintg() {cout << "This is the " << title << " painted by " << artist << " in " << year << endl;}
};

class ProformaceArt : public Art {
    protected:
        double duration;
    public:
        ProformaceArt(string a, string t, int y, string ty, double d) : Art(a, t, y, ty) {duration = d;}
        ProformaceArt() {}
        void applaud() {cout << "Applauding" << endl;}
        double getDuration() {return duration;}
};

class Song : public ProformaceArt {
    private:
        string writer;
    public:
        Song(string a, string t, int y, string ty, double d, string w) : ProformaceArt(a, t, y, ty, d) {writer = w;}
        Song() {}
};

class Album : public ProformaceArt {
    private:
        int numOfSongs;
        vector<Song> record;
    public:
        Album(string a, string t, int y, string ty, double d, int nos) : ProformaceArt(a, t, y, ty, d) {
            numOfSongs = nos;
        }
        void listenToAlbum() {
            cout << "Here is " << title << " by " << artist << " (" << duration << " min)" << endl;
            for (Song s : record) { 
                cout << "Listening to " << s.getTitle() << " by " << s.getArtist() << " (" << s.getDuration() << " min)" << endl;
            }
        }
        void addTrack(Song s) {record.push_back(s);}
        friend void playSingleTrack(vector<Album> al);
};

void playSingleTrack(vector<Album> al) {
    string albumChoice;
    cout << "Which album would you like to play?" << endl;
    getline(cin, albumChoice);
    for (Album a : al) {
        if (a.getTitle() == albumChoice) {
            cout << "Album found" << endl;
            string songChoice;
            cout << "Which song would you like to play?" << endl;
            getline(cin, songChoice);
            for (Song s : a.record) {
                if (s.getTitle() == songChoice) {
                    cout << "Playing " << s.getTitle() << " by " << s.getArtist() << " (" << s.getDuration() << " min)" << endl;
                } 
            }
        }
    }
}

void Art::display() {
    cout << title << " by " << artist << " (" << year << ") type: " << type << endl;  
}


int main() {
    // paintings
    Painting p = Painting("Leonardo Divinci", "Mona Lisa", 1503, "Painting", 30);

    // songs
    Song s = Song("Iron Maiden", "Fear Of The Dark", 1991, "Song", 7.5, "Bruce Dickinson");
    Song s2 = Song("Iron Maiden", "Afraid To Shoot Strangers", 1991, "Song", 6.5, "Bruce Dickinson");
    Song s3 = Song("Iron Maiden", "Be Quick Or Be Dead", 1991, "Song", 3.5, "Bruce Dickinson");
    Song s4 = Song("Megadeth", "Holy Wars", 1990, "Song", 6.5, "Dave Mustaine");
    Song s5 = Song("Megadeth", "Hangar 18", 1990, "Song", 6.5, "Dave Mustaine");
    Song s6 = Song("Megadeth", "Tornado Of Souls", 1990, "Song", 6.5, "Dave Mustaine");

    // albums
    Album a = Album("Iron Maiden", "Fear Of The Dark", 1991, "Album", 60, 12);
    Album a2 = Album("Megadeth", "Rust In Peace", 1990, "Album", 40.75, 9);
    // p.display();
    // s.display();
    // a.display();
    p.showCasePaintintg();

    cout << "-------------------------------------------------------------------------------" <<endl;

    a.addTrack(s);
    a.addTrack(s2);
    a.addTrack(s3);
    a2.addTrack(s4);
    a2.addTrack(s5);
    a2.addTrack(s6);
    a.listenToAlbum();
    a2.listenToAlbum();

    cout << "-------------------------------------------------------------------------------" <<endl;
    vector<Album> albums;
    albums.push_back(a);
    albums.push_back(a2);
    playSingleTrack(albums);

    cout << "-------------------------------------------------------------------------------" <<endl;

    // later change to work with dynamic array
    Art arr[] = {p, s, s2, s3, s4, s5, s6, a, a2};
    for (int i = 0; i < 9; i++) {
        arr[i].display();
    }
}