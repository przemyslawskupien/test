#include"musicbuddy.h"
#include<iostream>

void Chord::setChord(chromaticSteps root, chordTypes type)
{
    this -> root = root;
    this -> type = type;

    switch(type){
        case chordTypes::MAJOR: third = ++++++++root; 
                                fifth = ++++++root;
                                break;
        case chordTypes::MINOR: third = ++++++root; 
                                fifth = ++++++++root;
                                break;
        case chordTypes::DIMINISHED: third = ++++++root;
                                     fifth = ++++++root;
                                     break;
    }
}


Chord::Chord()
{
     std::cout << '\n' << "Ctor Chord" << '\n';
}


Chord::Chord(chromaticSteps root, chordTypes type) : root{root}, type{type}
{
     std::cout << '\n' << "Ctor Chord" << '\n';

      switch(type){
        case chordTypes::MAJOR: third = ++++++++root; 
                                fifth = ++++++root;
                                break;
        case chordTypes::MINOR: third = ++++++root; 
                                fifth = ++++++++root;
                                break;
        case chordTypes::DIMINISHED: third = ++++++root;
                                     fifth = ++++++root;
                                     break;
        }
}


Chord::~Chord(){
    std::cout << '\n' << "Dtor Chord" << '\n';
}

//////////////////////////////////////////////////////////////////////

Scale::Scale(chromaticSteps key, int size) : key{key}, size{size},
steps{new chromaticSteps [size]}, chords{new Chord[size]}
{
    std::cerr << "Ctor Scale" << std::endl;}


Scale::~Scale(){
    delete [] steps;
    delete [] chords;
    std::cerr << "Dtor Scale" << std::endl;
    }


void Scale::printScale(){
    std::cout << "Scale::printScale()" << std::endl;
    std::cout << key << " " << chords[0].type << " SCALE" << std::endl;

    int i = 0;
    chordNumbers number = chordNumbers::I;

    while (i<size){
        std::cout << steps[i] << " ";
        i++;
        }

    std::cout << '\n';
   
    for(i = 0; i != size; ++i, ++number){
        std::cout << number << ": " << chords[i] << '\n';
    }


    std::cout << std::endl;    
}


void Scale::printChords(){
    std::cout << "Scale::printChords()" << std::endl;
        for(int i = 0; i < this->getSize(); i++)
        std::cout << chords[i] << " ";
    std::cout << std::endl;
}


chromaticSteps Scale::getStep(int position){
        return this->steps[position];
    }


chromaticSteps Scale::getKey(){
    return this->key;
}


int Scale::getSize(){
    return this -> size;
}


void Scale::orTest(){
    std::cout << '\n' << "Base" << '\n';
}

/////////////////////////////////////////////////////////////////////

MinorScale::MinorScale(chromaticSteps key) : Scale(key, 7)
{
    std::cerr << "Ctor MinorScale" << std::endl;
    this->steps[0] = key;
    this->steps[1] = ++++key;
    this->steps[2] = ++key;
    this->steps[3] = ++++key;
    this->steps[4] = ++++key;
    this->steps[5] = ++key;
    this->steps[6] = ++++key;

    chords[0].setChord(steps[0], chordTypes::MINOR);
    chords[1].setChord(steps[1], chordTypes::DIMINISHED);
    chords[2].setChord(steps[2], chordTypes::MAJOR);
    chords[3].setChord(steps[3], chordTypes::MINOR);
    chords[4].setChord(steps[4], chordTypes::MINOR);
    chords[5].setChord(steps[5], chordTypes::MAJOR);
    chords[6].setChord(steps[6], chordTypes::MAJOR);

}


MinorScale::~MinorScale(){
    std::cerr << "Dtor MinorScale" << std::endl;
}


void MinorScale::orTest(){
    std::cout << '\n' << "Minor" << '\n';
}

/////////////////////////////////////////////////////////////////////////

MajorScale::MajorScale(chromaticSteps key) : Scale(key, 7)
{
    std::cerr << "Ctor MajorScale" << std::endl;

    steps[0] = key;
    steps[1] = ++++key;
    steps[2] = ++++key;
    steps[3] = ++key;
    steps[4] = ++++key;
    steps[5] = ++++key;
    steps[6] = ++++key;

    chords[0].setChord(steps[0], chordTypes::MAJOR);
    chords[1].setChord(steps[1], chordTypes::MINOR);
    chords[2].setChord(steps[2], chordTypes::MINOR);
    chords[3].setChord(steps[3], chordTypes::MAJOR);
    chords[4].setChord(steps[4], chordTypes::MAJOR);
    chords[5].setChord(steps[5], chordTypes::MINOR);
    chords[6].setChord(steps[6], chordTypes::DIMINISHED);
}


MajorScale::~MajorScale(){
    std::cerr << "Dtor MajorScale" << std::endl;
}


void MajorScale::orTest(){
    std::cout << '\n' << "Major" << '\n';
}

////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& stream, const chromaticSteps& step){
    switch(step){
        case chromaticSteps::A: return stream << "A"; 
        case chromaticSteps::ASHARP: return stream << "A#"; 
        case chromaticSteps::B: return stream << "B"; 
        case chromaticSteps::C: return stream << "C";
        case chromaticSteps::CSHARP: return stream << "C#"; 
        case chromaticSteps::D: return stream << "D";
        case chromaticSteps::DSHARP: return stream << "D#";
        case chromaticSteps::E: return stream << "E"; 
        case chromaticSteps::F: return stream << "F"; 
        case chromaticSteps::FSHARP: return stream << "F#";
        case chromaticSteps::G: return stream << "G";
        case chromaticSteps::GSHARP: return stream << "G#";
        default: return stream << "NONE";
    }  
}


std::ostream& operator<<(std::ostream& stream, const chordTypes& type){
    switch(type){
        case chordTypes::MAJOR: return stream << "MAJOR";
        case chordTypes::MINOR: return stream << "MINOR";
        case chordTypes::DIMINISHED: return stream << "DIMINISHED";
        default: return stream << "NONE";

    }
}


std::ostream& operator<<(std::ostream& stream, const Chord& chord){
     return stream << chord.root << " " << chord.type << " = " << chord.root << "+" << chord.third 
            << "+" << chord.fifth << std::endl;
 }


chromaticSteps& operator++(chromaticSteps& step){
    switch(step){
        case chromaticSteps::A: return step = chromaticSteps::ASHARP;
        case chromaticSteps::ASHARP: return step = chromaticSteps::B; 
        case chromaticSteps::B: return step = chromaticSteps::C; 
        case chromaticSteps::C: return step = chromaticSteps::CSHARP;
        case chromaticSteps::CSHARP: return step = chromaticSteps::D; 
        case chromaticSteps::D: return step = chromaticSteps::DSHARP;
        case chromaticSteps::DSHARP: return step = chromaticSteps::E;
        case chromaticSteps::E: return step = chromaticSteps::F; 
        case chromaticSteps::F: return step = chromaticSteps::FSHARP; 
        case chromaticSteps::FSHARP: return step = chromaticSteps::G;
        case chromaticSteps::G: return step = chromaticSteps::GSHARP;
        case chromaticSteps::GSHARP: return step = chromaticSteps::A;
        default: return step = chromaticSteps::B;
    }  
}


chordNumbers& operator++(chordNumbers& number){
    switch(number){
        case chordNumbers::I: return number = chordNumbers::II;
        case chordNumbers::II: return number = chordNumbers::III;
        case chordNumbers::III: return number = chordNumbers::IV;
        case chordNumbers::IV: return number = chordNumbers::V;
        case chordNumbers::V: return number = chordNumbers::VI;
        case chordNumbers::VI: return number = chordNumbers::VII;
        case chordNumbers::VII: return number = chordNumbers::I;
        default: return number = chordNumbers::I;

    }
}


std::ostream& operator<<(std::ostream& stream, const chordNumbers& number){
    switch(number){
        case chordNumbers::I: return stream << "I";
        case chordNumbers::II: return stream << "II";
        case chordNumbers::III: return stream << "III";
        case chordNumbers::IV: return stream << "IV";
        case chordNumbers::V: return stream << "V";
        case chordNumbers::VI: return stream << "VI";
        case chordNumbers::VII: return stream << "VII";
        default: return stream << "I";
    }
}
