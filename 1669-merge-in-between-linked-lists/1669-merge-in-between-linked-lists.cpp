#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto __untie_cin = cin.tie(nullptr);
auto __unsync_ios_stdio = ios_base::sync_with_stdio(false);

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        
        for (int i = 1; i < a; i++) {
            curr = curr->next;
        }

        for (int i = a; i <= b; i++) {
            curr->next = curr->next->next;
        }

        ListNode* tmp = curr->next;
        curr->next = list2;

        while (list2->next) {
            list2 = list2->next;
        }

        list2->next = tmp;

        return list1;
    }
};