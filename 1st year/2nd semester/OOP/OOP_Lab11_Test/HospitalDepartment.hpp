//
// Created by sysadmin on 16.05.2018.
//

#ifndef OOPTEST16MAI_HOSPITALDEPARTMENT_HPP
#define OOPTEST16MAI_HOSPITALDEPARTMENT_HPP

#include <iostream>
#include <string>

using namespace std;


class HospitalDepartment {
    public:
        HospitalDepartment(string &hospitalName, int noOfDocs) : hospitalName(hospitalName), noOfDocs(noOfDocs), efficient(false) {}

        void setNoOfDocs(int no) {
            this->noOfDocs = no;
        }

        const int getNoOfDocs() const {
            return this->noOfDocs;
        }

        void setHospitalName(string &name) {
            this->hospitalName = name;
        }

        const string getHospitalName() const {
            return this->hospitalName;
        }

        void setIsEfficient(bool eff) {
            this->efficient = eff;
        }

        virtual string toString() = 0;
        const bool isEfficient() const {
            return this->efficient;
        }

    private:
        string hospitalName;
        int noOfDocs;

        bool efficient;
};

class NeonatalUnit : public HospitalDepartment {
    public:
        NeonatalUnit(string &hospitalName, int noOfDocs, int noOfMothers, int noOfNewborns, double avgGrade)
                : HospitalDepartment(hospitalName, noOfDocs), noOfMothers(noOfMothers), noOfNewborns(noOfNewborns), avgGrade(avgGrade) {
            this->setIsEfficient(avgGrade > 8.5 && noOfNewborns > noOfMothers);
        }

        void setNoOfMothers(int no) {
            this->noOfMothers = no;
        }

        const int getNoOfMothers() const {
            return this->noOfMothers;
        }

        void setNoOfNewborns(int no) {
            this->noOfNewborns = no;
        }

        const int getNoOfNewborns() const {
            return this->noOfNewborns;
        }

        void setAvgGrade(double avg) {
            this->avgGrade = avg;
        }

        const double getAvgGrade() const {
            return this->avgGrade;
        }

        string toString() override {
            string res;
            res += "Type: Neonatal Unit";
            res += "; Hospital name: ";
            res += this->getHospitalName();
            res += "; number of docs: ";
            res += to_string(this->getNoOfDocs());
            res += "; number of mothers: ";
            res += to_string(this->getNoOfMothers());
            res += "; number of newborns: ";
            res += to_string(this->getNoOfNewborns());
            res += "; average grade of babies: ";
            res += to_string(this->getAvgGrade());
            res += "; is efficient: ";
            res += to_string(this->isEfficient());

            return res;
        }

    private:
        int noOfMothers;
        int noOfNewborns;
        double avgGrade;
};

class Surgery : public HospitalDepartment {
    public:
        Surgery(string &hospitalName, int noOfDocs, int noOfPatients)
                : HospitalDepartment(hospitalName, noOfDocs), noOfPatients(noOfPatients) {
            this->setIsEfficient(double(noOfPatients) / noOfDocs >= 2);
        }

        void setNoOfPatients(int no) {
            this->noOfPatients = no;
        }

        const int getNoOfPatients() const {
            return this->noOfPatients;
        }

        string toString() override {
            string res;
            res += "Type: Surgery";
            res += "; Hospital name: ";
            res += this->getHospitalName();
            res += "; number of docs: ";
            res += to_string(this->getNoOfDocs());
            res += "; number of patients: ";
            res += to_string(this->getNoOfPatients());
            res += "; is efficient: ";
            res += to_string(this->isEfficient());

            return res;
        }



    private:
        int noOfPatients;

};

#endif //OOPTEST16MAI_HOSPITALDEPARTMENT_HPP