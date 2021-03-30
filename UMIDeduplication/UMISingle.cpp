//
//  UMISingle.cpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/30/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#include "UMISingle.hpp"

using namespace std;

UMISingle::UMISingle(){
    umi = "";
    reads.clear();
    qss.clear();
    primers.clear();
}

UMISingle::UMISingle(std::string umi, std::string read){
    this->umi = umi;
    reads.clear();
    qss.clear();
    primers.clear();
    
    reads.push_back(read);
    qss.push_back("");
    primers.push_back("");
}

UMISingle::UMISingle(std::string umi, std::string read, std::string qs){
    this->umi = umi;
    reads.clear();
    qss.clear();
    primers.clear();
    
    reads.push_back(read);
    qss.push_back(qs);
    primers.push_back("");
}

UMISingle::UMISingle(std::string umi, std::string read, std::string qs, std::string primer){
    this->umi = umi;
    reads.clear();
    qss.clear();
    primers.clear();
    
    reads.push_back(read);
    qss.push_back(qs);
    primers.push_back(primer);
}

bool UMISingle::insert(std::string read){
    reads.push_back(read);
    qss.push_back("");
    primers.push_back("");
    return true;
}

bool UMISingle::insert(std::string read, std::string qs){
    reads.push_back(read);
    qss.push_back(qs);
    primers.push_back("");
    return true;
}

bool UMISingle::insert(std::string read, std::string qs, std::string primer){
    reads.push_back(read);
    qss.push_back(qs);
    primers.push_back(primer);
    return true;
}

bool UMISingle::insert(const UMISingle & other){
    if(umi != other.umi){
        return false;
    }
    
    reads.insert(reads.end(), other.reads.begin(), other.reads.end());
    qss.insert(qss.end(), other.qss.begin(), other.qss.end());
    primers.insert(primers.end(), other.primers.begin(), other.primers.end());
    return true;
}


bool UMISingle::deduplication(){
    return true;
}


bool UMISingle::operator<(const UMISingle &other) const{
    return(umi < other.umi);
}

UMISingle & UMISingle::operator=(const UMISingle &other){
    if(this == &other){
        return *this;
    }
    
    umi = other.umi;
    reads = other.reads;
    qss = other.qss;
    primers = other.primers;
    
    return *this;
}
