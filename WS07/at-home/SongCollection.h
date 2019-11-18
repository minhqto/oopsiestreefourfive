// Name: Minh To
// Seneca Student ID: 125526186
// Seneca email: qto@myseneca.ca
// Date of completion: 7 Nov 19
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <list>

namespace sdds
{
    struct Song{
        std::string artist;
        std::string title;
        std::string album;
        std::string price;
        std::string release_year;
        size_t length;
    };

    class SongCollection{
        std::vector<Song> listOfSongs;

    public:
        SongCollection(std::string);
        void display(std::ostream&) const;
        void sort(const std::string&);
        void cleanAlbum();
        bool inCollection(const std::string&) const;
        std::list<Song> getSongsForArtist(const std::string&) const;

    };
    std::ostream& operator<<(std::ostream&, const Song&);
    void checkBegSpace(std::string&);
    void removeTrailingSpaces(std::string&);

}

#endif
