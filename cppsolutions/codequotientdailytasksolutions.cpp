// #include <iostream>
// using namespace std;
// int factorial(int n){
//     if (n<=1){
// return 1;
//     }
//     else{
//         return n*factorial(n-1);
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     cout << factorial(n)<<endl;
//     return 0;

// }

// #include <iostream>
// using namespace std;
// int fibonacci(int n)
// {

//     if (n <= 1)
//     {
//         return n;
//     }
//     else
//     {
//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }
// int main()
// {
//     int n;
//     // cin >> n;
//     cout << fibonacci(5) << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int fibonacci(int n)
// {

//     if (n <= 1)
//     {
//         return n;
//     }
//     else
//     {

//         return fibonacci(n - 1) + fibonacci(n - 2);
//     }
// }

// void fibonaccifind(int n ,int a=0)
// {

//     if (n >a )
//     {
//         cout << fibonacci(a)<<endl;
//         fibonaccifind(n,a+1);
//     }
// }
// int main()
// {
//     int n;
//     // cin >> n;
//     fibonaccifind(10);

//     return 0;
// }

// #include <iostream>
// using namespace std;
// int arraysum(int arr[], int n)
// {

//     if (n == 1)
//     {
//         return arr[0];
//     }

//     return arr[n - 1] + arraysum(arr, n - 1);
// }
// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout << arraysum(arr, n) << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;
// int arraymax(int arr[],int n)
// {

//     if (n==1)
//     {
//        return arr[0];
//     }
//     int maxx=arraymax(arr+1,n-1);

//     return (maxx>arr[0])?maxx:arr[0];
// }
// int main()
// {
//     int n;
//     cin >> n;

//     int arr[n];

//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     cout << arraymax(arr,n)<<endl;

//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// void generatePermutations(string str, int left, int right)
// {
//     if (left == right)
//     {
//         cout << str << endl;
//     }
//     else
//     {
//         for (int i = left; i <= right; i++)
//         {
//             swap(str[left], str[i]);
//             generatePermutations(str, left + 1, right);
//             swap(str[left], str[i]);
//         }
//     }
// }

// int main()
// {
//     string input;
//     cin >> input;

//     int n = input.size();
//     generatePermutations(input, 0, n - 1);

//     return 0;
// }

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

void printList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the list: ";
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }


    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
