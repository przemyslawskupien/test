#ifndef _MUSICBUDDY_H
#define _MUSICBUDDY_H
#include<iostream>
enum class chromaticSteps {
    A, ASHARP, B, C, CSHARP, D, DSHARP, E, F, FSHARP, G, GSHARP
    };

enum class chordTypes {
    MAJOR, MINOR, DIMINISHED
};

enum class chordNumbers {
    I, II, III, IV, V, VI, VII
};

//////////////////////////////////////////////////////////////////////////

struct Chord {
    chromaticSteps root, third, fifth;
    chordTypes type;
    void setChord(chromaticSteps, chordTypes);

    Chord();
    Chord(chromaticSteps, chordTypes);
    ~Chord();
};

//////////////////////////////////////////////////////////////////////////

class Scale {
protected:
    chromaticSteps key;
    int size;
    chromaticSteps* steps;
    Chord* chords;

public:
    virtual ~Scale();
    Scale(chromaticSteps, int);
    chromaticSteps getKey();
    void printScale();
    void printChords();
    chromaticSteps getStep(int);
    int getSize();
    void orTest();

};

/////////////////////////////////////////////////////////////////////////////

class MinorScale : public Scale {
public:
    ~MinorScale();
    MinorScale(chromaticSteps);
    void orTest();
};

///////////////////////////////////////////////////////////////////////////////

class MajorScale : public Scale {
public:
    ~MajorScale();
    MajorScale(chromaticSteps);
    void orTest();
};

////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream&, const Chord&);
std::ostream& operator<<(std::ostream&, const chromaticSteps&);
chromaticSteps& operator++(chromaticSteps&);
std::ostream& operator<<(std::ostream&, const chordTypes&);
chordNumbers& operator++(chordNumbers& snumber);
std::ostream& operator<<(std::ostream&, const chordNumbers&);

#endif