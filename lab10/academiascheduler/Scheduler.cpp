//
// Created by Jan on 21.05.2018.
//

#include "Scheduler.h"


academia::Schedule academia::Schedule::OfTeacher(int teacher_id_) const {
    Schedule tmp ;

    for(int i=0; i<items.size(); i++ ){
        if(items[i].teacher_id == teacher_id_)
            tmp.items.emplace_back(items[i]);
    }
    return tmp;
}

academia::Schedule academia::Schedule::OfRoom(int room_id) const {
    Schedule tmp ;

    for(int i=0; i<items.size(); i++ ){
        if(items[i].room_id == room_id)
            tmp.items.emplace_back(items[i]);
    }
    return tmp;
}

academia::Schedule academia::Schedule::OfYear(int year) const {
    Schedule tmp ;

    for(int i=0; i<items.size(); i++ ){
        if(items[i].year == year)
            tmp.items.emplace_back(items[i]);
    }
    return tmp;
}

std::vector<int> academia::Schedule::AvailableTimeSlots(int n_time_slots) const {
    std::vector <int> wolne;

    for (int i=1; i<=n_time_slots; i++){
        wolne.emplace_back(i);
    }

    std::vector<int> v;
    std::vector<int> czas;

    std::set_intersection(taken_time_slots.begin(), taken_time_slots.end(),
                          wolne.begin(), wolne.end(),
                          std::back_inserter(v));

    std::set_difference(wolne.begin(), wolne.end(),
                        v.begin(), v.end(),
                        std::back_inserter(czas));

    return czas;
}

void academia::Schedule::InsertScheduleItem(const academia::SchedulingItem &item_) {
    SchedulingItem it = item_;
    taken_time_slots.emplace_back(item_.time_slot);
    items.emplace_back(it);
}

academia::SchedulingItem academia::Schedule::operator[](int iter) const {
    return items[iter];
}

size_t academia::Schedule::Size() const {
    return items.size();
}

academia::Schedule::Schedule(std::vector<academia::SchedulingItem> item_v) {
    for(auto it : item_v){
        InsertScheduleItem(it);
    }
}


academia::Schedule academia::GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                                 int n_time_slots) {

    std::vector<SchedulingItem> obiekty;
    int ilekursow;
    for (auto kursy : courses_of_year) {
        for (auto course : kursy.second) {
            ilekursow = 0;
            for (auto kursynaucz : teacher_courses_assignment) {
                ilekursow += std::count(kursynaucz.second.begin(), kursynaucz.second.end(), course);
            }
            if ( ilekursow > n_time_slots)
                throw NoViableSolutionFound();
        }
    }

    for(auto kursynaucz2 : teacher_courses_assignment) {
        for(auto kurs : kursynaucz2.second) {
            for(auto kursy2 : courses_of_year) {
                if(kursy2.second.find(kurs) != kursy2.second.end())
                    obiekty.push_back(SchedulingItem(kurs, kursynaucz2.first, 0, 0, kursy2.first));
            }
        }
    }

    if(obiekty.size() > rooms.size() * n_time_slots)
        throw NoViableSolutionFound{};

    int i =0;
    for(auto pokoj : rooms) {
        for (int time_slot = 1; time_slot <= n_time_slots; time_slot++){
            if(i<obiekty.size()) {
                obiekty[i].time_slot = time_slot;
                obiekty[i].room_id = pokoj;
            }
            i++;
        }
    }

    return Schedule{obiekty};
}

academia::SchedulingItem::SchedulingItem(int course_, int teacher_, int room_, int time_slot_, int year_) {
    course_id = course_;
    teacher_id = teacher_;
    room_id = room_;
    time_slot = time_slot_;
    year = year_;
}

int academia::SchedulingItem::CourseId() const {
    return course_id;
}

int academia::SchedulingItem::TeacherId() const {
    return teacher_id;
}

int academia::SchedulingItem::RoomId() const {
    return room_id;
}

int academia::SchedulingItem::TimeSlot() const{
    return time_slot;
}

int academia::SchedulingItem::Year() const {
    return year;
}