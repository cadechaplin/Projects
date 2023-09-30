#include "System.h"
void System::importCourseList() {


    Record temp;
    string token;
    string line;

    std::ifstream input;

    input.open("classList.csv", std::ios::in);

    if (input.is_open()) {

        getline(input, line);

    }

    while (input.is_open())
    {



        getline(input, line);
        char* dup = _strdup(line.c_str());



        if (line[0] == '\0') {
           
            input.close();
            input.open("classList.csv", std::ios::out | std::ofstream::trunc);
            input.close();
            StoreMasterList();
        }
        else
        {
            token = strtok(dup, ",");
            temp.setRecordNum(stoi(token));
            token = strtok(NULL, ",");
            temp.setIDnum(stoi(token));
            token = strtok(NULL, ",");
            token.erase(0, 1);
            temp.setLastName(token);
            token = strtok(NULL, ",");
            token.erase(token.size() - 1);
            temp.setFirstName(token);
            token = strtok(NULL, ",");
            temp.setEmail(token);
            token = strtok(NULL, ",");
            temp.setUnits(token);
            token = strtok(NULL, ",");
            temp.setMajor(token);
            token = strtok(NULL, ",");
            temp.setLevel(token);


            studentList.insert(temp);
           // cout << "input" << endl;

        }



        delete dup;

    }


}

void System::markAbsences() {

    Node<Record>* pCur = this->studentList.getHead();
    char choice = '\0';
   
   // Node<Record> pCum = *pCur;
    while (pCur != nullptr)
    {
        Record temp = pCur->getData();

        cout << "Was " << temp.getFirstName() << " " << temp.getLastName() << " absent? (y/n)" << endl;// fix overloaded cout 
        cin >> choice;
        if (choice == 'y') {
        

            temp.addAb(getDate());
            //temp.setTotalAb(temp.getTotalAb() + 1);
            //this->getCurDate()
            pCur->setData(temp);
           
        
        }
        else
        {

        }



        pCur = pCur->getNext();
    }





}

void System::StoreMasterList() {

    Node<Record>* pCur = studentList.getHead();
    std::ofstream output;

   output.open("masterList.csv", std::ios::out);

    

    while (output.is_open())
    {


        while (pCur != nullptr) {
            output << pCur->getData() << endl;

            pCur = pCur->getNext();

        }
        

        output.close();
    }

}

void System::importMasterList() {



    Record temp;
    string token;
    string line;
    int tempS;

    std::ifstream input;

    input.open("masterList.csv", std::ios::in);

    if (input.is_open()) {

        getline(input, line);

    }

    while (input.is_open())
    {



        getline(input, line);
        char* dup = _strdup(line.c_str());



        if (line[0] == '\0') {
           // input.clear();
            input.close();
        }
        else
        {
            token = strtok(dup, ",");
            temp.setRecordNum(stoi(token));
            token = strtok(NULL, ",");
            temp.setIDnum(stoi(token));
            token = strtok(NULL, ",");
            
            temp.setFirstName(token);
            token = strtok(NULL, ",");
           
            temp.setLastName(token);
            token = strtok(NULL, ",");
            temp.setEmail(token);
            token = strtok(NULL, ",");
            temp.setUnits(token);
            token = strtok(NULL, ",");
            temp.setMajor(token);
            token = strtok(NULL, ",");
            temp.setLevel(token);
            token = strtok(NULL, ",");
            tempS = stoi(token);

            for (size_t i = 0; i < tempS; i++)
            {
                token = strtok(NULL, ",");
                temp.addAb(token);

            }


            studentList.insert(temp);
            // cout << "input" << endl;

        }



        delete dup;

    }


}



void System::reportMenu() {

    cout << "All Students(1) or Absences filter(2)?" << endl;
        int x = 0;
        cin >> x;
        if (x == 1) {
            this->report1();
        
        }
        else if (x == 2) {
         this->report2();
        
        }
        else
        {
            cout << "bad input" << endl;
        }
   



}

void System::report1() {
    Node<Record>* pCur = studentList.getHead();

    while (pCur != nullptr) {
        Record temp = pCur->getData();

        //cout << temp << endl;
        cout << temp.getLastName() << ", "  << temp.getFirstName() << ", " << temp.peek() << endl;
    
    
        pCur = pCur->getNext();
    }




}
void System::report2() {
    int x = 0;
    cout << "Enter absences filter:" << endl;
    cin >> x;
    Node<Record>* pCur = studentList.getHead();

    while (pCur != nullptr) {

        
        Record temp = pCur->getData();

        if (temp.getTotalAb() > x-1) {



            cout << temp.getLastName() << ", " << temp.getFirstName() << ", " << temp.peek() << endl;


        }

        pCur = pCur->getNext();
    }







}


void System::editAbsence() {
    int choice = 0;
    cout << "What student? (IDnum)" << endl;
    cin >> choice;
    Node<Record>* pCur = studentList.getHead();
   
    bool success = false;
    while (pCur != nullptr)
    {

        Record temp = (pCur)->getData();
        if (choice == temp.getIDnum()) {
            success = true;
        

            if (temp.getTotalAb() == 0) {
            
                cout << "Student has no absences." << endl;
            
            }
            else {
                cout << "What date?" << endl;
                
                string dateChoice;
                cin >> dateChoice;

                temp.removeAb(dateChoice);
               
                /*
                AStack<string> date; 
                int i = 0;
                int dateChoice = 0;
                while (temp.getTotalAb() > 0)
                {


                    date.insert(temp.popAb());
                    cout << "(" << i << ") " << date.peek() << endl;

                    i++;
                }
                cin >> dateChoice;
                dateChoice = temp.getTotalAb() - dateChoice;
                while (temp.getTotalAb() > 0) {
                
                    if (i != dateChoice) {
                        temp.addAb(date.pop());


                    }


                
                
                
                }*/
                pCur->setData(temp);
                

            }
        
        
        }
        


        pCur = pCur->getNext();
    }
    if (!success) {
        cout << "no student with this ID found." << endl;
    
    }





}



string getDate() {
    
    time_t t = time(0);   // get time now

    struct tm* now = localtime(&t);
    string date = std::to_string(now->tm_year + 1900);
    date += '/';
    date += std::to_string(now->tm_mon + 1);
    date += '/';
    date += std::to_string(now->tm_mday);
    /*
    //date.append(itos(now->tm_year + 1900));
    text += std::to_string(i);
    cout << (now->tm_year + 1900) << '-'

        << (now->tm_mon + 1) << '-'

        << now->tm_mday

        << endl;
        */

    return date;
}

void System::run() {










    char choice = '\0';

    while (choice != '7') {
        cout << "1.    Import course list" << endl <<

            "2.    Load master list" << endl <<

            "3.    Store master list" << endl <<

            "4.    Mark absences" << endl <<

            "5.    BONUS: Edit absences" << endl <<

            "6.    Generate report" << endl <<

            "7.    Exit" << endl;

        cin >> choice;//change to getline'


        if (choice == '1') {
           importCourseList();
        }
        else if (choice == '2') {
            importMasterList();
        }
        else if (choice == '3') {
           StoreMasterList();
        }
        else if (choice == '4') {
            markAbsences();
        }
        else if (choice == '5') {
            editAbsence();
        }
        else if (choice == '6') {
            reportMenu();
        }
        else if (choice != '7')
        {
            cout << "bad input" << endl;
        }

    }
























}