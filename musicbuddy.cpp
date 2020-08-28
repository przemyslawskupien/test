#include"musicbuddy.h"
#include<iostream>

Chord::Chord(chromaticSteps root, chordTypes type) : root{root}, type{type}
{
    switch(type){
        case MAJOR: third = ++++++++root; 
                    fifth = ++++++root;
                    break;
        case MINOR: third = ++++++root; 
                    fifth = ++++++++root;
                    break;
    }
}

Chord::~Chord(){

}

Scale::Scale(chromaticSteps key, int size) : key{key}, size{size},
steps{new chromaticSteps [size]}, chords{new Chord[size]}
{
    std::cerr << "Ctor Scale" << std::endl;};

Scale::~Scale(){
    delete [] steps;
    delete [] chords;
    std::cerr << "Dtor Scale" << std::endl;
    }

    chromaticSteps Scale::getStep(int position){
        return this->steps[position];
    }

int Scale::getSize(){
    return this -> size;
}


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

}

MinorScale::~MinorScale(){
    std::cerr << "Dtor MinorScale" << std::endl;
}

chromaticSteps MinorScale::getKey(){
    return this->key;
}

void MinorScale::printScale(){
    std::cout << "MinorScale::printScale()" << std::endl;
    int i = 0;

    if(steps){
        while (i<size){
            std::cout << steps[i] << " ";
            i++;
        }
    }

    std::cout << std::endl;
}

void MinorScale::printChords(){
    std::cout << "MinorScale::printChords()" << std::endl;
        for(int i = 0; i < this->getSize(); i++)
        std::cout << chords[i] << " ";
    std::cout << std::endl;
}

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
}

MajorScale::~MajorScale(){
    std::cerr << "Dtor MajorScale" << std::endl;
}

chromaticSteps MajorScale::getKey(){
    return this->key;
}

void MajorScale::printScale(){
    std::cout << "MajorScale::printScale()" << std::endl;

    if(steps)
        for(int i = 0; i < size; ++i)
        std::cout << steps[i] << " ";
    std::cout << std::endl;

}
void MajorScale::printChords(){
    std::cout << "MajorScale::printChords()" << std::endl;

    if(chords)
        for(int i = 0; i < this->size; ++i)
        std::cout << chords[i] << " ";
    std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const chromaticSteps& step){
    switch(step){
        case A: return stream << "A"; 
        case ASHARP: return stream << "A#"; 
        case B: return stream << "B"; 
        case C: return stream << "C";
        case CSHARP: return stream << "C#"; 
        case D: return stream << "D";
        case DSHARP: return stream << "D#";
        case E: return stream << "E"; 
        case F: return stream << "F"; 
        case FSHARP: return stream << "F#";
        case G: return stream << "G";
        case GSHARP: return stream << "G#";
        default: return stream << "NONE";
    }  
}

std::ostream& operator<<(std::ostream& stream, const Chord& chord){
     return stream << chord.root << "+" << chord.third 
            << "+" << chord.fifth << std::endl;
 }

chromaticSteps& operator++(chromaticSteps& step){
    switch(step){
        case A: return step = chromaticSteps::ASHARP;
        case ASHARP: return step = chromaticSteps::B; 
        case B: return step = chromaticSteps::C; 
        case C: return step = chromaticSteps::CSHARP;
        case CSHARP: return step = chromaticSteps::D; 
        case D: return step = chromaticSteps::DSHARP;
        case DSHARP: return step = chromaticSteps::E;
        case E: return step = chromaticSteps::F; 
        case F: return step = chromaticSteps::FSHARP; 
        case FSHARP: return step = chromaticSteps::G;
        case G: return step = chromaticSteps::GSHARP;
        case GSHARP: return step = chromaticSteps::A;
        default: return step = chromaticSteps::B;
    }  
}