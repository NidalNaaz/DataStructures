#include <iostream>
#include <string>

using namespace std;

class Song {
    string title;
    string artist;
    int duration; 
    string genre;

public:
    Song(string tempTitle, string tempArtist, int tempDuration, string tempGenre) : title(tempTitle), artist(tempArtist), duration(tempDuration), genre(tempGenre) {}

    string getTitle() const 
    {
        return title;
    }

    string getArtist() const 
    {
        return artist;
    }

    int getDuration() const 
    {
        return duration;
    }

    string getGenre() const 
    {
        return genre;
    }

    void display() const 
    {
        cout << "Title: " << title << ", Artist: " << artist << ", Duration: " << duration << "s, Genre: " << genre << endl;
    }
};

class Node
{
    Song data;
    Node* link;

public:
    Node(Song tempData) : data(tempData), link(nullptr) {}

    Song getData() const 
    {
        return data;
    }

    void setData(Song tempData) 
    {
        data = tempData;
    }

    Node* getLink() const 
    {
        return link;
    }

    void setLink(Node* tempLink) 
    {
        link = tempLink;
    }
};

class Playlist 
{
    Node* head;

public:
    Playlist() : head(nullptr) {}

    void insert(Song tempSong) 
    {
        Node* newNode = new Node(tempSong);
        if (head == nullptr) 
        {
            head = newNode;
        } 
        else 
        {
            Node* current = head;
            while (current->getLink() != nullptr) 
            {
                current = current->getLink();
            }
            current->setLink(newNode);
        }
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            current->getData().display();
            current = current->getLink();
        }
    }

    void sortByTitle() 
    {
        if (head == nullptr || head->getLink() == nullptr) 
        {
            return; 
        }

        bool swapped;
        Node* tempPtr1;
        Node* lastPtr = nullptr;

        do 
        {
            swapped = false;
            tempPtr1 = head;

            while (tempPtr1->getLink() != lastPtr) 
            {
                if (tempPtr1->getData().getTitle() > tempPtr1->getLink()->getData().getTitle()) 
                {
                    
                    Song tempSong = tempPtr1->getData();
                    tempPtr1->setData(tempPtr1->getLink()->getData());
                    tempPtr1->getLink()->setData(tempSong);
                    swapped = true;
                }
                tempPtr1 = tempPtr1->getLink();
            }
            lastPtr = tempPtr1;
          
        } while (swapped);
    }
};

int main() 
{
    Playlist playlist;

    playlist.insert(Song("Twinkle Twinkle Little Star", "Cocomelon", 60, "Nursery Rhyme"));
    playlist.insert(Song("Blinding Lights", "The Weeknd", 200, "R&B"));
    playlist.insert(Song("Cupid", "Fifty-Fifty", 180, "Love"));
    playlist.insert(Song("Black Rover", "Vickeblanka", 210, "Anime"));

    cout << "Playlist before sorting by title:" << endl;
    playlist.display();
  
    playlist.sortByTitle();

    cout << "\nPlaylist after sorting by title:" << endl;
    playlist.display();

    return 0;
}
