//#include <unistd.h> /// ERASE THIS BEFORE TURNING IT IN.
#include <stdlib.h>
#include <stdio.h>
#define _GNU_SOURCE

struct queue {
	int payload; // The element our queue carries
	struct queue* next;  // Pointer to next queue struct
	struct queue* prev; // Pointer to previous queue struct
};

struct queue* h; // Head of the queue

struct queue* NewItem() { // returns a pointer to a new q-element
	struct queue* node = (struct queue*)malloc(sizeof(struct queue));
	return node;
}

void InitQueue(struct queue** head) { // creates an empty queue, pointed to by the variable head.
	h = NewItem();
	h = NULL;
	*head = h;
}

void AddQueue(struct queue** head, struct queue* item) { // adds a queue item, pointed to by “item”, to the queue pointed to by head.
	h = *head;
	if (h == NULL) {
		h = item;
		item->next = h;
		item->prev = h;
	}
	else {
		struct queue* temp = NewItem();
		temp = h;
		while (temp->next != h) {
			temp = temp->next;
		}
		temp->next = item;			// temp is the second to last element, item is the last element now
		temp->next->prev = temp;	// item's previous is temp
		h->prev = temp->next;		// head's previous is item.
		temp->next->next = h;		// item's next is head.
	}
	*head = h;
}

struct queue* DelQueue(struct queue** head) { // deletes an item from head and returns a pointer to the deleted item. If this is the last element…
	struct queue* temp = NewItem();
	h = *head;
	if (h == NULL) {
		printf("Queue is empty. Can not remove anything.\n");
	}
	else if (h->next == h) {
		temp = h;
		h->next = NULL;
		h->prev = NULL;
		h = NULL;
	}
	else {
		temp = h;
		h->prev->next = h->next;
		h->next->prev = h->prev;
		h = h->next;
	}
	*head = h;
	return temp;
}

void RotateQ(struct queue** head) { // Moves the header pointer to the next element in the queue.
	struct queue* tail = NewItem();
	h = *head;
	if (h == NULL) {
		printf("Queue is empty. Cannot rotate.\n");
	}
	else {
		h = h->next;
	}
	*head = h;
}
