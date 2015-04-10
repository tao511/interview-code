#ifndef INTERVIEW_SUM_LIST_NUMBER
#define INTERVIEW_SUM_LIST_NUMBER

class node
{
public:
  int data;
  node* next;

  node(int init_data): data(init_data), next(nullptr) {}
};

/**
 * Sum linked digits together.
 *
 * When digits are stored reversely, traverse through 
 * the list and sum all numbers together by p[i] * 10^(i),
 * where i is the index in the linked list, starting at 0.
 * 
 * When digits are stored sequentially, traverse once to 
 * determine the length L, then add all numbers together 
 * by p[i] * 10^(L-i), where L is the length of the list
 * and i is the index starting at 0.
 * 
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int sumListNumber(node* leftPtr, node* rightPtr, bool isReversed)
{
  // for reversed order
  int sum = 0;
  int base = 10;
  size_t cnt = 0;
  node* ptr = nullptr;

  // we did not test if data is always between 0-9

  if (isReversed) {
    ptr = leftPtr;
    cnt = 0;
    while (ptr != nullptr) {
      sum += ptr->data * pow(base, cnt++);
      ptr= ptr->next;
    }
    cnt = 0;
    ptr = rightPtr;
    while (ptr!= nullptr) {
      sum +=  ptr->data * pow(base, cnt++);
      ptr= ptr->next;
    }
  } else {

    // first get the length of number
    ptr = leftPtr;
    cnt = -1;
    while(ptr != nullptr) {
      ptr = ptr->next;
      cnt++;
    }

    ptr = leftPtr;
    while(ptr != nullptr) {
      sum += ptr->data * pow(base,cnt--);
      ptr = ptr->next;
    }

    ptr = rightPtr;
    cnt = -1;
    while(ptr != nullptr) {
      ptr = ptr->next;
      cnt++;
    }

    ptr = rightPtr;
    while(ptr != nullptr) {
      sum += ptr->data * pow(base, cnt--);
      ptr = ptr->next;
    }

  }

  return sum;

}

#endif
