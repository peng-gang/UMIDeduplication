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
    std::vector<std::string> reads;
    std::vector<std::string> qss;
    std::vector<std::string> primers;

public:
    UMI();
    UMI(std::string umi, std::string read);
    UMI(std::string umi, std::string read, std::string qs);
    UMI(std::string umi, std::string primer, std::string read, std::string qs);
    
    bool insert(std::string read);
    bool insert(std::string read, std::string qs);
    bool insert(std::string primer, std::string read, std::string qs);
    
    bool deduplication();
};

#endif /* UMI_hpp */
