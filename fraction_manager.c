#include<stdio.h>
#include<string.h>
#include<math.h>

struct fraction {
	int num;
	int denom;
} fractFirst, fractSecond, fractNew;

char functionChoice[1], shouldAdd[2] = {"a"}, shouldMult[2] = {"m"}, shouldDiv[2] = {"d"}, shouldSub[2] = {"s"};
int functionChoiceFinal, foundError = 0;

struct fraction simplify(struct fraction fractToSimplify)
{
	for (int potentialFactor = (fractToSimplify.num - (fractToSimplify.num % 2))/2; potentialFactor > 1; potentialFactor--)
	{
		if (fractToSimplify.denom % potentialFactor == 0 && fractToSimplify.num % potentialFactor == 0)
		{
			fractToSimplify.denom /= potentialFactor;
			fractToSimplify.num /= potentialFactor;
		}
	}

	return fractToSimplify;
}

struct fraction add(struct fraction x, struct fraction y)
{
	return simplify({x.num * y.denom + y.num * x.denom, x.denom * y.denom});
}

struct fraction mult(struct fraction x, struct fraction y)
{
	return simplify({x.num * y.num, x.denom * y.denom});
}

struct fraction div(struct fraction x, struct fraction y)
{
	return simplify({x.num * y.denom, y.num * x.denom});
}

struct fraction sub(struct fraction x, struct fraction y)
{
	return simplify({x.num * y.denom - y.num * x.denom, x.denom * y.denom});
}

void createFractionPair()
{
	printf("\nPlease enter a fraction\n\n");
	scanf("%d/%d", &fractFirst.num, &fractFirst.denom);
	printf("\nPlease enter another fraction\n\n");
	scanf("%d/%d", &fractSecond.num, &fractSecond.denom);
}

int operateOnPair()
{
	printf("\nWhat would you like to do with these fractions? ;)\n[a] add, [s] subtract, [m] multiply, [d] divide\n\n");
	scanf("%s", &functionChoice);

	if (strcmp(functionChoice, shouldAdd) == 0)
	{
		fractNew = add(fractFirst, fractSecond);
		printf("\n%d/%d + %d/%d = ", fractFirst.num, fractFirst.denom, fractSecond.num, fractSecond.denom);
	}

	else if (strcmp(functionChoice, shouldSub) == 0)
	{
		fractNew = sub(fractFirst, fractSecond);
		printf("\n%d/%d - %d/%d = ", fractFirst.num, fractFirst.denom, fractSecond.num, fractSecond.denom);
	}

	else if (strcmp(functionChoice, shouldMult) == 0)
	{
		fractNew = mult(fractFirst, fractSecond);
		printf("\n%d/%d * %d/%d = ", fractFirst.num, fractFirst.denom, fractSecond.num, fractSecond.denom);
	}

	else if (strcmp(functionChoice, shouldDiv) == 0)
	{
		fractNew = div(fractFirst, fractSecond);
		printf("\n%d/%d / %d/%d = ", fractFirst.num, fractFirst.denom, fractSecond.num, fractSecond.denom);
	}

	else
	{
		printf("\nINVALID INPUT. Stopping...\n\n ");
		return 0;
	}

	printf("%d/%d\n\nDo you want to do anything else?\n[1] different fractions, [2] different operations, same fractions, [3] quit\n\n", fractNew.num, fractNew.denom);
	scanf("%d", &functionChoiceFinal);

	if (functionChoiceFinal == 1)
	{
		createFractionPair();
		operateOnPair();
	}

	else if (functionChoiceFinal == 2)
	{
		operateOnPair();
	}

	else if (functionChoiceFinal == 3)
	{
		return 0;
	}

	else
	{
		printf("\nINVALID INPUT. Stopping...\n\n ");
		return 0;
	}

	return 0;
}

int main()
{
	createFractionPair();
	operateOnPair();
}

