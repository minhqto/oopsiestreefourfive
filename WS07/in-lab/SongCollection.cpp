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
        auto displayLamb = [=, &out](const Song& theSong){out << theSong;};
        std::for_each(listOfSongs.begin(), listOfSongs.end(), displayLamb);
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
        out <<  theSong.price << " |" << std::endl;

        return out;
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
