// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 7 Nov 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include "SongCollection.h"

namespace sdds {
    SongCollection::SongCollection(const std::string fileName) {

        try {
            std::ifstream file(fileName);
            Song songToBePushed;
            std::string tempSong;
            if (!file) {
                throw "No file exists";
            }
            do {
                    std::getline(file, tempSong);
                    songToBePushed.title = tempSong.substr(0, 25);

                        songToBePushed.artist = tempSong.substr(25, 25);
                        songToBePushed.album = tempSong.substr(50, 25);
                        songToBePushed.release_year = tempSong.substr(75, 5);
                        songToBePushed.length = std::stoi(tempSong.substr(80, 5));
                        songToBePushed.price = tempSong.substr(85, 5);

                        checkBegSpace(songToBePushed.title);
                        checkBegSpace(songToBePushed.album);
                        checkBegSpace(songToBePushed.artist);

                        removeTrailingSpaces(songToBePushed.title);
                        removeTrailingSpaces(songToBePushed.artist);
                        removeTrailingSpaces(songToBePushed.album);
                        removeTrailingSpaces(songToBePushed.release_year);
                        removeTrailingSpaces(songToBePushed.price);

                        listOfSongs.push_back(songToBePushed);


            } while (file && !file.eof());

        } catch (const char *msg) {
            std::cout << msg << std::endl;
        }
    }

    void SongCollection::display(std::ostream &out) const {
        size_t totalTime = 0;
        size_t hours = 0;
        size_t min = 0;
        size_t minInSec = 0;
        size_t sec = 0;

        auto displayLamb = [=, &out](const Song& theSong){out << theSong << std::endl;};
        auto sumPlayTime = [&](const Song& theSong){totalTime += theSong.length;};
        std::for_each(listOfSongs.begin(), listOfSongs.end(), displayLamb);
        std::for_each(listOfSongs.begin(), listOfSongs.end(), sumPlayTime);

        hours = totalTime / 3600;
        minInSec = totalTime % 3600;
        min = minInSec / 60;

        sec =  minInSec % 60;
        out << "----------------------------------------------------------------------------------------" << std::endl;
        out << "|";
        out.width(78);
        out << "Total Listening Time: " << hours << ":" << min << ":";

        out.setf(std::ios::fixed);
        out.precision(2);
        out << sec;
        out.unsetf(std::ios::fixed);
        out.setf(std::ios::right);
        out.unsetf(std::ios::right);
        out << " |" << std::endl;
    }

    std::ostream& operator<<(std::ostream &out, const Song &theSong) {

        size_t tempMin = 0;
        size_t tempSec = 0;

        out << "| ";
        out <<std::setw(20) << std::left << theSong.title << " | ";
        out << std::setw(15) << theSong.artist << " | ";
        out << std::setw(20) << theSong.album << " | " << std::setw(6);
        out.setf(std::ios::right);
        out << theSong.release_year << " | ";
        out.unsetf(std::ios::right);

        tempMin = theSong.length / 60;
        tempSec = theSong.length % 60;
        out << tempMin << ":";
        out.width(2);
        out.setf(std::ios::right);
        out.fill('0');
        out << tempSec << " | ";
        out.fill(' ');
        out.unsetf(std::ios::left);
        out <<  theSong.price << " |";

        return out;
    }

    void SongCollection::sort(const std::string &src)
    {
        //sort the vector based on the string given ex "title.

        if(src == "title"){
            auto sortTitle = [](const Song &firstSong, const Song &secondSong){
                return firstSong.title < secondSong.title;
            };
            std::sort(listOfSongs.begin(), listOfSongs.end(), sortTitle);
        }
        if(src == "length"){
            auto sortLength = [](const Song &firstSong, const Song &secondSong){
                return firstSong.length < secondSong.length;
            };
            std::sort(listOfSongs.begin(), listOfSongs.end(), sortLength);
        }

    }

    void SongCollection::cleanAlbum()
    {
        auto clean = [&](Song& aSong) {
            if (aSong.album == "[None]") {
                aSong.album = "";
            }
        };
        std::for_each(listOfSongs.begin(), listOfSongs.end(), clean);
    }

    bool SongCollection::inCollection(const std::string &anArtist) const
    {
        bool containsName = false;
        auto songInCollection = [&](const Song &aSong){
            return aSong.artist == anArtist ? true : false;
        };
        containsName = std::any_of(listOfSongs.begin(), listOfSongs.end(), songInCollection);

        return containsName;
    }

    std::list<Song> SongCollection::getSongsForArtist(const std::string &anArtist) const
    {
        std::list<Song> artistsAvail;
        auto artistToList = [&](const Song &aSong) {
            if(aSong.artist == anArtist) {
                artistsAvail.push_back(aSong);
            }
        };
        std::for_each(listOfSongs.begin(), listOfSongs.end(), artistToList);
        return artistsAvail;
    }

    void checkBegSpace(std::string& src)
    {
        while(src[0] == ' '){
            src.erase(0, 1);
        }
    }

    void removeTrailingSpaces(std::string& src)
    {
        size_t endSpace = src.find_last_not_of(' ');
        src.erase(endSpace + 1);
    }

}
