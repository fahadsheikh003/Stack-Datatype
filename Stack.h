#pragma once
//Fahad Waheed

template <typename T>
class Stack
{
	struct Node
	{
		T data;
		Node* next;
		Node* previous;

		Node() : data(T()), next(NULL), previous(NULL) {};

		Node(T data) : data(data), next(NULL), previous(NULL) {};
	};

	Node* top, * bottom;

public:
	Stack() : top(NULL), bottom(NULL) {};

	Stack(const Stack<T>& obj) : top(NULL), bottom(NULL)
	{
		Node* currnode = obj.bottom;

		while (currnode)
		{
			push(currnode->data);
			currnode = currnode->previous;
		}
	}

	Stack& operator=(const Stack<T>& obj)
	{
		this->clear();
		Node* currnode = obj.bottom;

		while (currnode)
		{
			push(currnode->data);
			currnode = currnode->previous;
		}
		return *this;
	}

	bool isEmpty()
	{
		return top == NULL && bottom == NULL;
	}

	void push(T data)
	{
		if (isEmpty())
		{
			top = bottom = new Node(data);
		}
		else
		{
			Node* newNode = new Node(data);
			newNode->next = top;
			top->previous = newNode;
			top = newNode;
		}
	}

	T pop()
	{
		if (!isEmpty())
		{
			T data = top->data;

			if (top == bottom)
			{
				delete top;
				top = bottom = NULL;
			}
			else
			{
				Node* temp = top;
				top = top->next;
				top->previous = NULL;
				delete temp;
			}
			
			return data;
		}
		return T();
	}

	T Top()
	{
		if (top)
			return top->data;
		return T();
	}

	T Bottom()
	{
		if (bottom)
		{
			return bottom->data;
		}
		return T();
	}

	void clear()
	{
		Node* currnode = top;
		while (currnode)
		{
			top = top->next;
			delete currnode;
			currnode = top;
		}
	}

	~Stack()
	{
		clear();
	}
};