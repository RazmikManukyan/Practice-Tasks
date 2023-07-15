#ifndef TICKET_BOOKING_SYSTEM_FOR_CINEMA_MOVIE_H
#define TICKET_BOOKING_SYSTEM_FOR_CINEMA_MOVIE_H
#include <iostream>
#include <vector>

class Movie {
    std::string title;
    int duration;
    std::string rating;
    std::vector<std::string> showTimes;
public:
    Movie(const std::string &title, int duration, const std::string &rating)
            : title(title), duration(duration), rating(rating) {}

    const std::string &getTitle() const {
        return title;
    }

    int getDuration() const {
        return duration;
    }

    const std::string &getRating() const {
        return rating;
    }

    const std::vector<std::string> getShowTimes() const {
        return showTimes;
    }

    void addShowTime(const std::string &showTime) {
        showTimes.push_back(showTime);
    }
};





#endif //TICKET_BOOKING_SYSTEM_FOR_CINEMA_MOVIE_H
