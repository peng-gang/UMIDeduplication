//
//  UMI.cpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/29/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#include "UMI.hpp"

using namespace std;

UMI::UMI(){
    umi = "";
    reads1.clear();
    reads2.clear();
    qss1.clear();
    qss2.clear();
    primers1.clear();
    primers2.clear();
}

UMI::UMI(std::string umi, std::string read1, std::string read2){
    this->umi = umi;
    reads1.clear();
    reads2.clear();
    qss1.clear();
    qss2.clear();
    primers1.clear();
    primers2.clear();
    
    reads1.push_back(read1);
    reads2.push_back(read2);
    qss1.push_back("");
    qss2.push_back("");
    primers1.push_back("");
    primers2.push_back("");
}

UMI::UMI(std::string umi, std::string read1, std::string read2, std::string qs1, std::string qs2){
    this->umi = umi;
    reads1.clear();
    reads2.clear();
    qss1.clear();
    qss2.clear();
    primers1.clear();
    primers2.clear();
    
    reads1.push_back(read1);
    reads2.push_back(read2);
    qss1.push_back(qs1);
    qss2.push_back(qs2);
    primers1.push_back("");
    primers2.push_back("");
}

UMI::UMI(std::string umi, std::string read1, std::string read2, std::string qs1, std::string qs2, std::string primer1, std::string primer2){
    this->umi = umi;
    reads1.clear();
    reads2.clear();
    qss1.clear();
    qss2.clear();
    primers1.clear();
    primers2.clear();
    
    reads1.push_back(read1);
    reads2.push_back(read2);
    qss1.push_back(qs1);
    qss2.push_back(qs2);
    primers1.push_back(primer1);
    primers2.push_back(primer2);
}

bool UMI::insert(std::string read1, std::string read2){
    reads1.push_back(read1);
    reads2.push_back(read2);
    qss1.push_back("");
    qss2.push_back("");
    primers1.push_back("");
    primers2.push_back("");
    return true;
}

bool UMI::insert(std::string read1, std::string read2, std::string qs1, std::string qs2){
    reads1.push_back(read1);
    reads2.push_back(read2);
    qss1.push_back(qs1);
    qss2.push_back(qs2);
    primers1.push_back("");
    primers2.push_back("");
    return true;
}

bool UMI::insert(std::string read1, std::string read2, std::string qs1, std::string qs2, std::string primer1, std::string primer2){
    reads1.push_back(read1);
    reads2.push_back(read2);
    qss1.push_back(qs1);
    qss2.push_back(qs2);
    primers1.push_back(primer1);
    primers2.push_back(primer2);
    return true;
}

bool UMI::insear(const UMI & other){
    if(umi!=other.umi){
        return false;
    }
    
    reads1.insert(reads1.end(), other.reads1.begin(), other.reads1.end());
    reads2.insert(reads2.end(), other.reads2.begin(), other.reads2.end());
    
    qss1.insert(qss1.end(), other.qss1.begin(), other.qss1.end());
    qss2.insert(qss2.end(), other.qss2.begin(), other.qss2.end());
    
    primers1.insert(primers1.end(), other.primers1.begin(), other.primers1.end());
    primers2.insert(primers2.end(), other.primers2.begin(), other.primers2.end());
    
    return true;
}


bool UMI::deduplication(){
    return true;
}


bool UMI::operator<(const UMI &other) const{
    return(umi < other.umi);
}

UMI & UMI::operator=(const UMI &other){
    if(this == &other){
        return *this;
    }
    
    umi = other.umi;
    reads1 = other.reads1;
    qss1 = other.qss1;
    primers1 = other.primers1;
    
    reads2 = other.reads2;
    qss2 = other.qss2;
    primers2 = other.primers2;
    
    return *this;
}
