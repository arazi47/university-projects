//
// Created by sysadmin on 09.04.2018.
//

#include <iostream>
#include "FileManager.h"


void FileManager::loadFromFile(vector<Axolotl>& vec) {
    ifstream in("/home/sysadmin/OOP/outfilevectorall.txt");

    Axolotl axolotl;

    while (in >> axolotl) {
        vec.push_back(axolotl);
    }
}

/*
void FileManager::exportAsHTML(const vector<Axolotl>& vec) {
    ofstream out("outfile.html");
    out << "<!DOCTYPE html>" << endl;
    out << "<html>" << endl;
    out << "<head><title>Pet list</title></head>" << endl;
    out << "<body style=\"background-color:powderblue;\"><table border=\"1\">" << endl;

    out << "<tr>" << endl;
    out << "<td>Name</td>" << endl;
    out << "<td>Age</td>" << endl;
    out << "<td>Breed</td>" << endl;
    out << "<td>Photo</td>" << endl;
    out << "</tr>" << endl;

    for (const auto& axolotl : vec) {
        out << "<tr>" << endl;
        out << "<td>" << axolotl.getName() << "</td>" << endl;
        out << "<td>" << axolotl.getAge() << "</td>" << endl;
        out << "<td>" << Axolotl::getStringFromBreed(axolotl.getBreed()) << "</td>" << endl;
        out << "<td>" << axolotl.getPhoto() << "</td>" << endl;
        out << "</tr>" << endl;
    }

    out << "</table>" << endl;
    out << "</body>" << endl;
    out << "</html>" << endl;
}

void FileManager::exportAsTextFile(const vector<Axolotl>& vec, const string& fileName) {
    ofstream out(fileName);
    for (const auto& axolotl : vec) {
        string output;
        output += axolotl.getName() + ",";
        output += to_string(axolotl.getAge()) + ",";
        output += to_string(Axolotl::getIntFromBreed(axolotl.getBreed())) += ",";
        output += axolotl.getPhoto();

        out << output << endl;
    }
}
*/

void TextFileManager::writeToFile(const vector<Axolotl> &vec, const string &fileName) {
    ofstream out(fileName);
    for (const auto& axolotl : vec) {
        string output;
        output += axolotl.getName() + ",";
        output += to_string(axolotl.getAge()) + ",";
        output += to_string(Axolotl::getIntFromBreed(axolotl.getBreed())) += ",";
        output += axolotl.getPhoto();

        out << output << endl;
    }
}

void HTMLFileManager::writeToFile(const vector<Axolotl> &vec, const string &fileName) {
    ofstream out(fileName);
    out << "<!DOCTYPE html>" << endl;
    out << "<html>" << endl;
    out << "<head><title>Pet list</title></head>" << endl;
    out << "<body style=\"background-color:powderblue;\"><table border=\"1\">" << endl;

    out << "<tr>" << endl;
    out << "<td>Name</td>" << endl;
    out << "<td>Age</td>" << endl;
    out << "<td>Breed</td>" << endl;
    out << "<td>Photo</td>" << endl;
    out << "</tr>" << endl;

    for (const auto& axolotl : vec) {
        out << "<tr>" << endl;
        out << "<td>" << axolotl.getName() << "</td>" << endl;
        out << "<td>" << axolotl.getAge() << "</td>" << endl;
        out << "<td>" << Axolotl::getStringFromBreed(axolotl.getBreed()) << "</td>" << endl;
        out << "<td>" << axolotl.getPhoto() << "</td>" << endl;
        out << "</tr>" << endl;
    }

    out << "</table>" << endl;
    out << "</body>" << endl;
    out << "</html>" << endl;
}
