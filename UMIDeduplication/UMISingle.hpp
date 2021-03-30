//
//  UMISingle.hpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/30/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#ifndef UMISingle_hpp
#define UMISingle_hpp

#include <stdio.h>
#include <string>
#include <vector>

class UMISingle{
private:
    std::string umi;
    std::vector<std::string> reads;
    std::vector<std::string> qss;
    std::vector<std::string> primers;

public:
    UMISingle();
    UMISingle(std::string umi, std::string read);
    UMISingle(std::string umi, std::string read, std::string qs);
    UMISingle(std::string umi, std::string read, std::string qs, std::string primer);
    
    bool insert(std::string read);
    bool insert(std::string read, std::string qs);
    bool insert(std::string read, std::string qs, std::string primer);
    bool insert(const UMISingle & other);
    
    std::string getUMI() {return umi;}
    std::vector<std::string> getReads() {return reads;}
    std::vector<std::string> getQss() {return qss;}
    std::vector<std::string> getPrimers1() {return primers;}
    
    std::size_t getNumReads() {return reads.size();}
    
    UMISingle & operator= (const UMISingle & other);
    bool operator< (const UMISingle & other) const;
    
    bool deduplication();
};
#endif /* UMISingle_hpp */
