#define TAGMASK_NOSCRATCH (((1 << LENGTH(tags)) - 1))
/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
void
shiftview(const Arg *arg)
{
	Arg a;
	Client *c;
	unsigned visible = 0;
	int i = arg->i;
	int count = 0;
	int nextseltags = 0;
    int curseltags = selmon->tagset[selmon->seltags];
    curseltags &= TAGMASK_NOSCRATCH;

	do {
		if(i > 0) // left circular shift
			nextseltags = (
                    (curseltags << i) | 
                    (curseltags >> (LENGTH(tags) - i))
                    ) & TAGMASK_NOSCRATCH;

		else // right circular shift
			nextseltags = (
                    (curseltags >> (- i)) | 
                    (curseltags << (LENGTH(tags) + i))
                    ) & TAGMASK_NOSCRATCH;

                // Check if tag is visible
		for (c = selmon->clients; c && !visible; c = c->next)
			if (nextseltags & c->tags) {
				visible = 1;
				break;
			}
		i += arg->i;
	} while (!visible && ++count < 10);

	if (count < 10) {
		a.ui = nextseltags;
		view(&a);
	}
}

void
shifttag(const Arg *arg)
{
	Arg a;
	Client *c;
	unsigned visible = 0;
	int i = arg->i;
	int count = 0;
	int nextseltags, curseltags = selmon->tagset[selmon->seltags] & TAGMASK_NOSCRATCH;

	do {
		if(i > 0) // left circular shift
			nextseltags = ((curseltags << i) | (curseltags >> (LENGTH(tags) - i))) & TAGMASK_NOSCRATCH;

		else // right circular shift
			nextseltags = (curseltags >> (- i) | (curseltags << (LENGTH(tags) + i))) & TAGMASK_NOSCRATCH;

                // Check if tag is visible
		for (c = selmon->clients; c && !visible; c = c->next)
			if (nextseltags & c->tags) {
				visible = 1;
				break;
			}
		i += arg->i;
	} while (!visible && ++count < 10);

	if (count < 10) {
		a.ui = nextseltags;
		tag(&a);
	}
}
