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

            void SetEntryData(string url, string encoded, std::unique_ptr<TinyUrlCodec> *tinyUrlCodec) {
                (*tinyUrlCodec)->tinyUrlEntry[encoded] = url;
            }
            string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec) {
                for (auto it = (*codec)->tinyUrlEntry.begin();
                     it != (*codec)->tinyUrlEntry.end(); ++it) // checks if url already encoded, return hash
                    if (it->second == url)
                        return it->first;
                string encodedUrl;
                for (char c : FirstHash)
                    encodedUrl += c;

                (*codec)->tinyUrlEntry[encodedUrl] = url;
                NextHash(&FirstHash);
                return encodedUrl;
            }

            string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash) {
                if (codec->tinyUrlEntry.find(hash) != codec->tinyUrlEntry.end())
                    return codec->tinyUrlEntry[hash];
                else
                    return "notfound";
            }

        }
