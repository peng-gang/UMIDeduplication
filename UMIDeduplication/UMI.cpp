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
    reads.clear();
    qss.clear();
    primers.clear();
}

UMI::UMI(std::string umi, std::string read){
    this->umi = umi;
    reads.clear();
    reads.push_back(read);
}

UMI::UMI(std::string umi, std::string read, std::string qs){
    this->umi = umi;
    reads.clear();
    qss.clear();
    
    reads.push_back(read);
    qss.push_back(qs);
}

UMI::UMI(std::string umi, std::string primer, std::string read, std::string qs){
    this->umi = umi;
    reads.clear();
    qss.clear();
    primers.clear();
    
    primers.push_back(primer);
    reads.push_back(read);
    qss.push_back(qs);
}

bool UMI::insert(std::string read){
    reads.push_back(read);
    return true;
}

bool UMI::insert(std::string read, std::string qs){
    reads.push_back(read);
    qss.push_back(qs);
    return true;
}

bool UMI::insert(std::string primer, std::string read, std::string qs){
    reads.push_back(read);
    qss.push_back(qs);
    primers.push_back(primer);
    return true;
}


bool UMI::deduplication(){
    return true;
}
