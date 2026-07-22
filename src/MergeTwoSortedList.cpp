#include <iostream>
using namespace std;


// Linked List 節點結構
struct ListNode {

    int val;              // 節點存放的值
    ListNode *next;       // 指向下一個節點的 pointer


    // 建立空節點
    ListNode() : val(0), next(nullptr) {}


    // 建立只有值的節點
    ListNode(int x) : val(x), next(nullptr) {}


    // 建立節點並指定下一個節點
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};



class Solution {

public:

    // 合併兩個已排序 linked list
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


        // 建立 dummy node
        // dummy 不存資料，只是方便操作
        ListNode dummy(0);


        // cur 指向目前結果 linked list 的尾端
        ListNode *cur = &dummy;



        // 當兩個 list 都還有節點
        while(list1 && list2){


            // 比較兩個節點的值
            if(list1->val < list2->val){


                // 將 list1 節點接到結果
                cur->next = list1;


                // list1 往下一個節點移動
                list1 = list1->next;

            }


            else{


                // 將 list2 節點接到結果
                cur->next = list2;


                // list2 往下一個節點移動
                list2 = list2->next;

            }


            // cur 往後移動
            cur = cur->next;

        }



        // 如果 list1 還有剩餘節點
        // 直接接上
        if(list1){

            cur->next = list1;

        }


        // 否則接 list2 剩餘節點
        else{

            cur->next = list2;

        }



        // 回傳真正的 head
        // dummy 是假的頭，不需要回傳
        return dummy.next;

    }

};



// 建立 linked list
ListNode* createList(initializer_list<int> nums){

    ListNode* head = nullptr;
    ListNode* tail = nullptr;


    for(int num : nums){


        // 建立新節點
        ListNode* node = new ListNode(num);



        // 第一個節點
        if(head == nullptr){

            head = node;
            tail = node;

        }


        else{

            tail->next = node;
            tail = node;

        }

    }


    return head;

}



// 印出 linked list
void printList(ListNode* head){


    while(head){

        cout << head->val;


        if(head->next)
            cout << " -> ";


        head = head->next;

    }


    cout << endl;

}



int main(){


    /*
        list1:
        1 -> 2 -> 4

        list2:
        1 -> 3 -> 4
    */


    ListNode* list1 = createList({1,2,4});

    ListNode* list2 = createList({1,3,4});



    Solution sol;


    // 合併
    ListNode* result = sol.mergeTwoLists(list1,list2);



    cout << "Merged List: ";

    printList(result);

    system("pause");

    return 0;

}