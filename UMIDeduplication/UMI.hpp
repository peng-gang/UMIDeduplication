//
//  UMI.hpp
//  UMIDeduplication
//
//  Created by Gang Peng on 3/29/21.
//  Copyright © 2021 Gang Peng. All rights reserved.
//

#ifndef UMI_hpp
#define UMI_hpp

#include <stdio.h>
#include <string>
#include <vector>

class UMI{
private:
    std::string umi;
    std::vector<std::string> reads1;
    std::vector<std::string> qss1;
    std::vector<std::string> primers1;
    
    std::vector<std::string> reads2;
    std::vector<std::string> qss2;
    std::vector<std::string> primers2;

public:
    UMI();
    UMI(std::string umi, std::string read1, std::string read2);
    UMI(std::string umi, std::string read1, std::string read2, std::string qs1, std::string qs2);
    UMI(std::string umi, std::string read1, std::string read2, std::string qs1, std::string qs2, std::string primer1, std::string primer2);
    
    bool insert(std::string read1, std::string read2);
    bool insert(std::string read1, std::string read2, std::string qs1, std::string qs2);
    bool insert(std::string read1, std::string read2, std::string qs1, std::string qs2, std::string primer1, std::string primer2);
    bool insear(const UMI & other);
    
    std::string getUMI() {return umi;}
    std::vector<std::string> getReads1() {return reads1;}
    std::vector<std::string> getReads2() {return reads2;}
    std::vector<std::string> getQss1() {return qss1;}
    std::vector<std::string> getQss2() {return qss2;}
    std::vector<std::string> getPrimers1() {return primers1;}
    std::vector<std::string> getPrimers2() {return primers2;}
    
    std::size_t getNumReads() {return reads1.size();}
    
    UMI & operator= (const UMI & other);
    bool operator< (const UMI & other) const;
    
    bool deduplication();
};

#endif /* UMI_hpp */
