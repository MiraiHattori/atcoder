#!/usr/bin/env bash

prefix=`LANG=C date +%Y-%m-%d-%H-%M-%S-`
for f in "a.cpp" "b.cpp" "c.cpp" "d.cpp" "e.cpp" "f.cpp"
do
    if [ -f "$f" ]; then
        mv $f $prefix$f
    fi
done


for f in "a.cpp" "b.cpp" "c.cpp" "d.cpp" "e.cpp" "f.cpp"
do
    echo -e \
"#include <iostream>
int main()
{
    int N;
    std::cin >> N;
    return 0;
}" \
>> $f
done
