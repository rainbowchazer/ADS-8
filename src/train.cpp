// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

int Train::getOpCount() {
	return countOp;
}

void Train::addCage(bool light) {
	Cage* nc = new Cage;
	if (first == nullptr) {
		first = nc;
		first->next = first;
		first->prev = first;
	} else {
		nc->next = first;
		nc->prev = first->prev;
		first->prev = nc;
		nc->prev->next = nc;
  }
	nc->light = light;
}

int Train::getLength() {
	Cage* ptr = first;
	ptr->light = 1;
	int count = 1;
	while (ptr) {
		ptr = ptr -> next;
		if (ptr->light == 0) {
			count++;
			countOp++;
		}
		if (ptr->light == 1) {
			countOp++;
			ptr->light = 0;
			for (int i = count; i > 0; i--) {
				ptr = ptr->prev;
				countOp++;
			}
			if (ptr->light == 0) {
				return count;
			}
			count = 1;
		}
	}
	return -1;
}
