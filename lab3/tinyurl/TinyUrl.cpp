//
// Created by Maciej Syska on 18/03/2018.
//

#include "TinyUrl.h"

        using std::string;
        using std::unique_ptr;
        using std::make_unique;

        namespace tinyurl
        {
            std::array<char,6> FirstHash={'0','0','0','0','0','0'};

            unique_ptr<TinyUrlCodec> Init() {
                unique_ptr<TinyUrlCodec> uniqueTinyUrlPtr = make_unique<TinyUrlCodec>();
                return uniqueTinyUrlPtr;
            }

            void NextHash(std::array<char, 6> *state) {
                bool zwieksznast=false;
                for(int i=5;i>=0;i--){

                    char znak=(*state)[i];
                    if(i==5 or zwieksznast==true){
                        znak=znak+1;
                        zwieksznast=false;
                    }
                    if(znak==58){
                        znak=65;
                    }
                    else if(znak==91){
                        znak=97;
                    }
                    else if(znak==123){
                        znak=48;
                        zwieksznast=true;
                    }
                    (*state)[i]=znak;

                }}



            string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
                for (auto tmp = (*codec)->UrlStart.begin();
                     tmp != (*codec)->UrlStart.end(); ++tmp)
                    if (tmp->second == url){
                        return tmp->first;}
                string newUrl;

                for (char c : FirstHash)
                    newUrl += c;

                (*codec)->UrlStart[newUrl] = url;
                NextHash(&FirstHash);
                return newUrl;
            }

            string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
                if (codec->UrlStart.find(hash) != codec->UrlStart.end())
                {
                    return codec->UrlStart[hash];
                }
                else
                    return "brak w bazie";
            }

        }
