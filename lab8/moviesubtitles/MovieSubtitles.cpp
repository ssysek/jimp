//
// Created by Sysek on 2018-05-07.
//

#include "MovieSubtitles.h"

#include "MovieSubtitles.h"

void moviesubs::SubRipSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, stringstream *in, stringstream *out) {

    regex wzor1 {R"((\d{2}):(\d{2}):(\d{2}),(\d{3}) --> (\d{2}):(\d{2}):(\d{2}),(\d{3}))"};
    regex wzor2 {R"((^\d\n))"};
    regex wzor3 {R"(^\d$)"};
    regex wzor4 {R"((\n\d\n))"};
    smatch rownosc;
    smatch rownosc_pierwsza_klatka;
    smatch klatka;
    smatch kolejnosc;
    int numer_linijki=0;
    bool boo = false;

    if(frame_per_second < 0 ){

        throw std::invalid_argument("Błąd: Liczba klatek nie może być ujemna");

    }

    string stringwej = (*in).str();
    std::regex_search(stringwej, rownosc_pierwsza_klatka, wzor2);
    int pierwszka_klatka_numer = stoi(rownosc_pierwsza_klatka[1]);
    int poprzedni = pierwszka_klatka_numer;
    std::regex_search(stringwej, kolejnosc, wzor4);

    for(int i = 1; i < kolejnosc.size() ; i++, poprzedni++) {

        if (stoi(kolejnosc[i]) != poprzedni+1) {

            throw OutOfOrderFrames();

        }

    }

    string wejstring= "";

    while(getline(*in,wejstring,'\n')) {

        if (std::regex_search(wejstring, rownosc, wzor1)) {

            numer_linijki++;
            boo = false;
            *out << rownosc[1] << ":" << rownosc[2] << ":";
            int opoznienie4 = stoi(rownosc[4].str()) + offset_in_micro_seconds;
            int opoznienie3 = stoi(rownosc[3])+opoznienie4/1000;
            string string_wzor3 = to_string(opoznienie3);
            string string_wzor4 = rownosc[4].str();

            if(opoznienie4 < 1000) {

                while(string_wzor4.size() < 3) {

                    string_wzor4 = '0' + string_wzor4;

                }

                while(string_wzor3.size()<2){

                    string_wzor3='0'+string_wzor3;

                }

                (*out)<< string_wzor3 << "," << opoznienie4 << " --> ";

            }

            else {

                string_wzor4 = to_string(opoznienie4%1000);

                while(string_wzor4.size()<3) {

                    string_wzor4 = '0' + string_wzor4;

                }

                while(string_wzor3.size()<2){

                    string_wzor3='0'+string_wzor3;

                }

                (*out)<< string_wzor3 << "," << string_wzor4 << " --> ";

            }


            *out << rownosc[5] << ":" << rownosc[6] << ":";
            string string_wzor8 = rownosc[8].str();
            int opoznienie8 = stoi(rownosc[8].str()) + offset_in_micro_seconds;
            int opoznienie7 = stoi(rownosc[7])+opoznienie8/1000;
            string string_wzor7 = to_string(opoznienie7);

            if(opoznienie8 < 1000) {

                while(string_wzor8.size() < 3) {

                    string_wzor8 = '0' + string_wzor8;

                }

                while(string_wzor7.size() < 2) {

                    string_wzor7 = '0' + string_wzor7;

                }

                (*out)<< string_wzor7 << "," << string_wzor8 << " --> ";

            }

            else{

                string_wzor8 = to_string(opoznienie8%1000);

                while(string_wzor8.size() < 3){

                    string_wzor8 = '0' + string_wzor8;

                }

                while(string_wzor7.size() < 2) {

                    string_wzor7 = '0' + string_wzor7;

                }

                (*out)<< string_wzor7 << "," << string_wzor8 << '\n';

            }

            if(opoznienie3 < 0 || opoznienie4 < 0 || opoznienie7 < 0 || opoznienie8 < 0) {

                throw NegativeFrameAfterShift();

            }

            if (stoi(rownosc[1]) * 3600 + stoi(rownosc[2]) * 60 + stoi(rownosc[3]) + stoi(rownosc[4]) * 0.001 >= stoi(rownosc[5]) * 3600 + stoi(rownosc[6]) * 60 + stoi(rownosc[7]) + stoi(rownosc[8]) * 0.001) {

                throw moviesubs::SubtitleEndBeforeStart(numer_linijki, wejstring);

            }

        }

        else {

            if(boo) {

                throw InvalidSubtitleLineFormat();

            }

            if (std::regex_search(wejstring, klatka, wzor3)) {

                boo = true;

            }

            *out << wejstring << '\n';

        }

    }

}

void moviesubs::MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, stringstream *in, stringstream *out) {

    string stringwej = (*in).str();
    regex wzor {R"(\{(\d+)\}\{(\d+)\}(.*))"};
    smatch rownosc;
    int numer_linii=0;

    if (frame_per_second < 0 ) {

        throw invalid_argument("Błąd: Liczba klatek nie może być ujemna");

    }

    while(getline(*in,stringwej,'\n')) {

        numer_linii++;

        if (std::regex_search(stringwej, rownosc, wzor)) {

            int start = stoi(rownosc[1]) + (offset_in_micro_seconds * frame_per_second / 1000);
            int koniec = stoi(rownosc[2]) + (offset_in_micro_seconds * frame_per_second / 1000);

            if (start < 0 || koniec < 0 ){

                throw moviesubs::NegativeFrameAfterShift();

            }

            if (koniec < start){

                throw moviesubs::SubtitleEndBeforeStart(numer_linii, stringwej);

            }

            *out << "{" << start << "}";
            *out << "{" << koniec << "}";
            *out << rownosc[3] << "\n";

        }

        else {

            throw moviesubs::InvalidSubtitleLineFormat();

        }

    }

}

int moviesubs::SubtitleEndBeforeStart::LineAt() const {

    return numer_linii;

}

string moviesubs::SubtitleEndBeforeStart::what() const {

    return "Linijka: " + to_string(numer_linii) + ": " + linijka;

}

moviesubs::SubtitleEndBeforeStart::SubtitleEndBeforeStart(int _numer_linii, string linijka_) {

    numer_linii = _numer_linii;
    linijka = linijka_;

}