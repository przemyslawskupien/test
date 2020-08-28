#ifndef _MUSICBUDDY_H
#define _MUSICBUDDY_H
#include<iostream>
enum chromaticSteps {
    A, ASHARP, B, C, CSHARP, D, DSHARP, E, F, FSHARP, G, GSHARP
    };

enum chordTypes {
    MAJOR, MINOR
};

struct Chord {
    chromaticSteps root, third, fifth;
    chordTypes type;

    Chord(chromaticSteps = C, chordTypes = MAJOR);
    ~Chord();
};

class Scale {
protected:
    chromaticSteps key;
    int size;
    chromaticSteps* steps;
    Chord* chords;

public:
    virtual ~Scale();
    Scale(chromaticSteps, int);
    virtual chromaticSteps getKey() = 0;
    virtual void printScale() = 0;
    virtual void printChords() = 0;
    chromaticSteps getStep(int);
    int getSize();
    void orTest();

};

class MinorScale : public Scale {
public:
    ~MinorScale();
    MinorScale(chromaticSteps);
    chromaticSteps getKey();
    void printScale();
    void printChords();
    void orTest();
};

class MajorScale : public Scale {
public:
    ~MajorScale();
    MajorScale(chromaticSteps);
    chromaticSteps getKey();
    void printScale();
    void printChords();
    void orTest();
};

std::ostream& operator<<(std::ostream&, const Chord&);
std::ostream& operator<<(std::ostream&, const chromaticSteps&);
chromaticSteps& operator++(chromaticSteps&);


#endif