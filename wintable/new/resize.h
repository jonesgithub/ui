// 7 december 2014

// TODO why doesn't this trigger on first show?
// TODO last few bits of the scrollbar series, that talk about WM_WINDOWPOSCHANGING and the metaphor
// TODO rename this to boot

HANDLER(resizeHandler)
{
	WINDOWPOS *wp;

	if (uMsg != WM_WINDOWPOSCHANGED)
		return FALSE;
	wp = (WINDOWPOS *) lParam;
	if ((wp->flags & SWP_NOSIZE) != 0)
		return FALSE;
	// this will call repositionHeader(); there's a good reason... (see comments)
	// TODO when I clean that mess up, remove this comment
	updateTableWidth(t);
	*lResult = 0;
	return TRUE;
}