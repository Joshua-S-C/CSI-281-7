//  Joshua Sinclair Chong
//  test.cpp
//
//  Tests to prove your code works.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include "Queue.h"
#include "Stack.h"
#include "catch.h"
#include <string>

using namespace std;
using namespace csi281;

// Ensure that push(), pop(), and peek()
// work properly in concert with getCount()
// and remove()

TEST_CASE( "Queue Tests", "[queue]" ) {
    SECTION( "Queue w/ int tests" ) {
        // Initialize
        Queue<int> q1 = Queue<int>();
        int length = 7;
        int qInts[7] = {-5, 3, 7, 1, 9, -1, 999};
        for (int i = 0; i < 7; i++)
            q1.push(qInts[i]);

        // Checks
        CHECK(q1.getCount() == length);
        CHECK(q1.peek() == -5);

        // Push
        q1.push(7);
        CHECK(q1.getCount() == length + 1);

        // Pop
        CHECK(q1.pop() == -5);
        CHECK(q1.getCount() == length);
        CHECK(q1.peek() == 3);

        // Remove
        q1.remove(999);
        CHECK(q1.getCount() == length-1);

        // Remove not found
        q1.remove(999);
        CHECK(q1.getCount() == length - 1);
    }
    
    SECTION( "Queue w/ string tests" ) {
        Queue<string> q2 = Queue<string>();
        std::string insert[3] = {"Hi", "Hello", "Bonjour"};

        for (int i = 0; i < 3; i++) {
            q2.push(insert[i]);
            CHECK(q2.getCount() == i + 1);
        }

        CHECK(q2.peek() == "Hi");

        CHECK(q2.pop() == "Hi");
        CHECK(q2.peek() == "Hello");
        CHECK(q2.getCount() == 2);

        q2.remove("Hello");
        CHECK(q2.peek() == "Bonjour");
        CHECK(q2.getCount() == 1);
    }
}

TEST_CASE( "Stack Tests", "[stack]" ) {
    SECTION( "Stack w/ int tests" ) {
        Stack<int> s1 = Stack<int>();
        int length = 7;
        int sInts[7] = { -5, 3, 7, 1, 9, -1, 999 };
        for (int i = 0; i < 7; i++)
            s1.push(sInts[i]);

        // Checks
        CHECK(s1.getCount() == length);
        CHECK(s1.peek() == 999);

        // Push
        s1.push(7);
        CHECK(s1.peek() == 7);
        CHECK(s1.getCount() == length + 1);

        // Pop
        CHECK(s1.pop() == 7);
        CHECK(s1.getCount() == length);

        // Remove
        s1.remove(999);
        CHECK(s1.getCount() == length - 1);
        CHECK(s1.peek() == -1);

        // Remove not found
        s1.remove(999);
        CHECK(s1.getCount() == length - 1);
    }
    
    SECTION( "Stack w/ string tests" ) {
        Stack<string> s2 = Stack<string>();
        std::string insert[3] = { "Hi", "Hello", "Bonjour" };

        for (int i = 0; i < 3; i++) {
            s2.push(insert[i]);
            CHECK(s2.getCount() == i + 1);
        }

        CHECK(s2.peek() == "Bonjour");

        CHECK(s2.pop() == "Bonjour");
        CHECK(s2.peek() == "Hello");
        CHECK(s2.getCount() == 2);

        s2.remove("Hello");
        CHECK(s2.peek() == "Hi");
        CHECK(s2.getCount() == 1);
    }
}

