//
//  UMISingleGroup.cpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/30/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#include "UMISingleGroup.hpp"
#include <iostream>
#include <fstream>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>

using namespace std;

UMISingleGroup::UMISingleGroup(){
    numReads = 0;
    umis.clear();
}

UMISingleGroup::UMISingleGroup(std::string inputFile, bool gzFile){
    numReads = 0;
    umis.clear();
    if(gzFile){
        ifstream file(inputFile.c_str(), ios_base::in | ios_base::binary);
        try {
            boost::iostreams::filtering_istream fin;
            fin.push(boost::iostreams::gzip_decompressor());
            fin.push(file);
            
            while(true){
                std::string identifier;
                if(!std::getline(fin, identifier)){
                    break;
                }
                
                std::string read;
                if(!std::getline(fin, read)){
                    break;
                }
                
                std::string opt;
                if(!std::getline(fin, opt)){
                    break;
                }
                
                std::string qs;
                if(!std::getline(fin, qs)){
                    break;
                }
                
                string umi = read.substr(0, 9);
                map<string, UMISingle>::iterator it = umis.find(umi);
                if(it != umis.end()){
                    //cout<<umi<<endl;
                    it->second.insert(read, qs, "");
                } else {
                    UMISingle umiObj(umi, read, qs, "");
                    umis.insert(pair<string, UMISingle> (umi, umiObj));
                }
                
                numReads++;
                
                /*
                if(numReads > 1000){
                    break;
                }
                 */
            }
        }
        catch(const boost::iostreams::gzip_error& e) {
             std::cout << e.what() << '\n';
        }
        file.close();
    } else {
        umis.clear();
    }
}

UMISingle UMISingleGroup::getUMI(std::string umi){
    map<string, UMISingle>::iterator it = umis.find(umi);
    if(it == umis.end()){
        return UMISingle();
    } else {
        return it->second;
    }
}

bool UMISingleGroup::insert(UMISingle umi){
    map<string, UMISingle>::iterator it = umis.find(umi.getUMI());
    if(it != umis.end()){
        it->second.insert(umi);
        
    } else {
        umis.insert(pair<string, UMISingle> (umi.getUMI(), umi));
    }
    return true;
}

bool UMISingleGroup::clear(){
    numReads = 0;
    umis.clear();
    return true;
}

std::map<std::string, std::size_t> UMISingleGroup::getNumUMIReads(){
    std::map<std::string, std::size_t> rlt;
    
    for(map<string, UMISingle>::iterator it = umis.begin(); it != umis.end(); it++){
        rlt.insert(pair<string, size_t> (it->first, it->second.getNumReads()));
    }
    
    return rlt;
}
