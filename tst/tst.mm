#include "header.h"
#import <XCTest/XCTest.h>

@interface tst : XCTestCase

@end

@implementation tst

- (void)testExample {
    int N;
    cout << "N: "; cin >> N;
    StudentInfo* p = new StudentInfo[N];
    int testIntFunc =  TwoScore(p, N);
    
    XCTAssertNotEqual(testIntFunc, -1);
    
}



@end
