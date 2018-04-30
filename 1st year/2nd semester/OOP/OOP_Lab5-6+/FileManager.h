//
// Created by sysadmin on 09.04.2018.
//

#ifndef LAB5_6_FILEMANAGER_H
#define LAB5_6_FILEMANAGER_H

#include <fstream>
#include <vector>
#include "Axolotl.h"

class FileManager {
    public:
        FileManager() = default;
        virtual ~FileManager() = default;

        static void loadFromFile(vector<Axolotl>& vec);

        //void exportAsHTML(const vector<Axolotl>& vec);
        //void exportAsTextFile(const vector<Axolotl>& vec, const string& fileName);

        virtual void writeToFile(const vector<Axolotl>& vec, const string& fileName) = 0;
};

class TextFileManager : public FileManager {
    public:
        TextFileManager() = default;

        void writeToFile(const vector<Axolotl>& vec, const string& fileName) override;
};

class HTMLFileManager : public FileManager {
    public:
        HTMLFileManager() = default;

        void writeToFile(const vector<Axolotl>& vec, const string& fileName) override;
};


#endif //LAB5_6_FILEMANAGER_H
