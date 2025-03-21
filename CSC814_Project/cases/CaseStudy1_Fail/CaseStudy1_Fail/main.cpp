#include <iostream>
#include <string>
using namespace std;

struct user {
	int bal = 0;
	string output = "Null";
	string id;
	char* states;
};

void printUserState(user usr, int t);

int main() {
    user User1, User2, User3;

    char User_1_States[] = { 'D', 'D', 'D', 'W', 'D', 'L' };
    char User_2_States[] = { 'D', 'D', 'W', 'D', 'R', 'W' };
    char User_3_States[] = { 'D', 'D', 'D', 'W', 'D', 'D' };

    User1.states = User_1_States;
    User2.states = User_2_States;
    User3.states = User_3_States;

    User1.id = "U1";
    User2.id = "U2";
    User3.id = "U3";

    user users[] = { User1, User2, User3 };

    int left(int index, int size);
    int right(int index, int size);

    int num_iterations = sizeof(User_1_States) / sizeof(User_1_States[0]);
    int num_users = sizeof(users) / sizeof(users[0]);

    for (int timer = 0; timer < num_iterations; timer++) {
        cout << "Iteration: " << timer << "\n";

        for (int i = 0; i < num_users; i++) {
            user* usr = &users[i];
            user* target = &users[i];

            switch (usr->states[timer]) {
            case 'D':
                if (usr->bal < 5) {
                    usr->bal++;
                    usr->output = "Deposit Successful";
                }
                else {
                    usr->output = "Deposit Failed";
                }
                break;
            case 'W':
                if (usr->bal > 0) {
                    usr->bal--;
                    usr->output = "Withdrawal Successful";
                }
                else {
                    usr->output = "Withdrawal Failed";
                }
                break;
            case 'L':
                target = &users[left(i, num_users)];
                if (usr->bal > 0 && target->bal < 5) {
                    usr->bal--;
                    users[left(i, num_users)].bal++;
                    usr->output = "Transfer Successful";
                }
                else {
                    usr->output = "Transfer Failed";
                }
                break;
            case 'R':
                target = &users[right(i, num_users)];
                if (usr->bal > 0 && target->bal < 5) {
                    usr->bal--;
                    users[right(i, num_users)].bal++;
                    usr->output = "Transfer Successful";
                }
                else {
                    usr->output = "Transfer Failed";
                }
                break;
            default:
                usr->output = "No Action";
                break;
            }
            printUserState(*usr, timer);
        }
    }
}

void printUserState(user usr, int t) {
	cout << "User : " << usr.id;
	cout << "\tState: " << usr.states[t];
	cout << "\tBal: " << usr.bal;
	cout << "\tOutput: " << usr.output << "\n";
}


int left(int index, int size) {
	return (index > 0 ? index - 1 : size - 1);
}
int right(int index, int size) {
	return (index < size -1 ? index + 1 : 0 );
}