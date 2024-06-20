
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

class Patient {
public:
    int patient_id;
    string name;
    string dob;
    string gender;
    Patient* next;

    Patient(int patientId, string name, string dob, string gender)
            : patient_id(patientId), name(std::move(name)), dob(std::move(dob)), gender(std::move(gender)), next(nullptr) {}
};
class PatientLinkedList{
private:
    Patient* head;

public:
    PatientLinkedList() : head(nullptr){}

    Patient* findPatient(int patient_id) {
        Patient* current = head;
        while (current) {
            if (current->patient_id ==  patient_id)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void addPatient(int patient_id, string name, string dob, string gender){
        Patient* patientExists = this->findPatient(patient_id);
        if(patientExists != nullptr){
            cerr<<"this id exists"<<endl;
            return;
        }

        auto* newPatient = new Patient(patient_id, std::move(name), std::move(dob), std::move(gender));

        if(!head){
            head = newPatient;
        }else{
            Patient* current = head;
            while (current->next){
                current = current->next;
            }
            current->next = newPatient;
        }

        cout << "registered" << endl;
    }

    void displayPatients(){
        Patient *node = head;
        while (node != nullptr){
            cout<<"Patient ID: "<<node->patient_id<<",  Name: "<<node->name<<",  DOB: "<<node->dob<<",  Gender: "<<node->gender<<endl;
            node = node->next;
        }
    }
};

class Doctor{
public:
    int doctor_id;
    string name;
    string specialization;
    Doctor* next;

    Doctor(int doctorId, string name, string specialization)
            : doctor_id(doctorId),name(std::move(name)),specialization(std::move(specialization)),next(nullptr) {}

};
class DoctorsLinkedList{
private:
    Doctor* head;

public:

    DoctorsLinkedList(): head(nullptr){}

    Doctor* findDoctor(int doctor_id) {
        Doctor* current = head;
        while (current) {
            if (current->doctor_id ==  doctor_id)
                return current;
            current = current->next;
        }
        return nullptr;
    }
    void addDoctor(int doctor_id, string name, string specialization){
        Doctor* doctorExists = this->findDoctor(doctor_id);
        if(doctorExists != nullptr){
            cerr<<"Given ID ALREADY EXIST"<<endl;
            return;
        }

        auto* newDoctor = new Doctor(doctor_id, std::move(name), std::move(specialization));

        if(!head){
            head = newDoctor;
        }else{
            Doctor* current = head;
            while(current->next){
                current = current->next;
            }
            current->next = newDoctor;
        }
        cout<<"registered"<<endl;
    }

    void displayDoctors(){
        Doctor *node = head;
        while (node != nullptr){
            cout<<"Doctor ID: "<<node->doctor_id<<",  Name: "<<node->name<<",  Specialization: "<<node->specialization<<endl;
            node = node->next;
        }
    }
};

class Appointment{
public:
    int appointment_id;
    int patient_id;
    int doctor_id;
    string appointment_date;
    Appointment* next;

    Appointment(int appointmentId, int patientId, int doctorId, string appointmentDate) : appointment_id(
            appointmentId), patient_id(patientId), doctor_id(doctorId), appointment_date(std::move(appointmentDate)), next(nullptr) {}

};

class Appointments{
private:
    Appointment* head;

public:
    Appointments() : head(nullptr){}

    Appointment* finAppointment(int appointment_id) {
        Appointment* current = head;
        while (current) {
            if (current->appointment_id ==  appointment_id)
                return current;
            current = current->next;
        }
        return nullptr;
    }
    void addAppointment( int appointment_id, int doctor_id, int patient_id, string appointment_date){

        auto* newAppointment = new Appointment(appointment_id, patient_id, doctor_id, appointment_date);

        if(!head){
            head = newAppointment;
        }else{
            Appointment* current = head;
            while (current->next){
                current = current->next;
            }
            current->next = newAppointment;
        }
        cout << "registered"<<endl;
    }

    void displayAppointments(){
        Appointment* node = head;
        while (node != nullptr){
            cout<<"Appointment ID: "<<node->appointment_id<<",  Patient ID: "<<node->patient_id<<",  Doctor ID: "<<node->doctor_id<<",  Date: "<<node->appointment_date<<endl;
            node = node->next;
        }
    }
};

void show_menu(){
    cout<<"Menu:"<<endl;
    cout<<"1. Register a patient"<<endl;
    cout<<"2. Register a doctor"<<endl;
    cout<<"3. Register an appointment"<<endl;
    cout<<"4. Display Patient"<<endl;
    cout<<"5. Display Doctor"<<endl;
    cout<<"6. Display Appointment"<<endl;
    cout<<"7. Exit"<<endl;
}

int main() {

    PatientLinkedList patientsLinkedList;
    DoctorsLinkedList doctorsLinkedList;
    Appointments appointmentsLinkedlist;

    while (true){
        show_menu();
        int choice;
        cout << "Enter your choice: "<<endl;
        cin>>choice;

        if(choice == 1){
            int id;
            string name, dob, gender;
            cout<<"PATIENT REGISTRATION"<<endl;
            cout<<"-----------------------"<<endl;
            cout<<"ID: ";
            cin>>id;
            cout<<"NAME: ";
            cin>>name;
            cout<<"DoB: ";
            cin>>dob;
            cout<<"GENDER: ";
            cin>>gender;
            patientsLinkedList.addPatient(id, name, dob,gender);
        }else if (choice == 2){
            int id;
            string name, specialization;
            cout<<"DOCTOR REGISTRATION"<<endl;
            cout<<"-----------------------"<<endl;
            cout<<"ID: ";
            cin>>id;
            cout<<"NAME: ";
            cin>>name;
            cout<<"SPECIALIZATION: ";
            cin>>specialization;
            doctorsLinkedList.addDoctor(id, name, specialization);
        }else if(choice == 3) {
            int id, patient_id, doctor_id;
            string date;
            cout<<"APPOINTMENT REGISTRATION"<<endl;
            cout<<"-----------------------"<<endl;
            cout<<"ID: ";
            cin>>id;
            cout<<"P_ID: ";
            cin>>patient_id;
            cout<<"D_ID: ";
            cin>>doctor_id;
            cout<<"DATE";
            cin>>date;
            appointmentsLinkedlist.addAppointment(id, doctor_id, patient_id, date);
        }else if(choice == 4){
            patientsLinkedList.displayPatients();
        }else if(choice == 5){
            doctorsLinkedList.displayDoctors();
        }else if(choice == 6){
            appointmentsLinkedlist.displayAppointments();
        }else if(choice == 7){
            break;
        }else{
            cout<<"Invalid input choice"<<endl;
        }
    }
}