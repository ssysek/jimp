//
// Created by Jan on 21.05.2018.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>



namespace academia {

    class SchedulingItem {
    public:
        SchedulingItem(int course_, int teacher_, int room_, int time_slot_, int year_);
        ~SchedulingItem(){};

        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    };

    class Schedule {
    public:
        Schedule () {}
        ~Schedule() {}
        Schedule (std::vector <SchedulingItem> item_v);

        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        std::vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item_);
        size_t Size() const;

        std::vector<SchedulingItem> items;
        std::vector<int> taken_time_slots;

        SchedulingItem operator[](int iter) const;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) = 0;
    };

    class GreedyScheduler : public Scheduler{
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms, const std::map<int, std::vector<int>> &teacher_courses_assignment, const std::map<int, std::set<int>> &courses_of_year, int n_time_slots);
    };


    class NoViableSolutionFound {
    public:
    };

}

#endif //JIMP_EXERCISES_SCHEDULER_H