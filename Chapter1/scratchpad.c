
  int i, j, idx, len, tabs, spaces, whitespaces;
  char c;
  
  /* Finds string length 'len' */
  len = 0;
  while (s[len]!='\0') len++;
  
  /* entabs */
  tabs = spaces = whitespaces = 0;
  i = len-1;
  while (i >= 0)
  {
    c = s[i];
    
    if(c==' ' && i>0)
    {
      /* is previous character on a tab stop */
      if ((i+1)%tab_width == 0)
        tabs++;
      else if (tabs == 0) 
        spaces++;
      
      whitespaces++;
    }
    else if (tabs!=0 || spaces!=0) /* new word found */
    {
      /* writes tabs over spaces */
      j = 0;
      while (j < tabs)
      {
        s[i+j+1] = '\t';
        j++;
      }
        
      /* index of start character for previous word */
      idx = i + whitespaces + 1;
      
      /* compress white space into tabs and spaces */
      j = idx;
      do
      {
        c = s[j];
        
        s[j-(whitespaces-tabs-spaces)] = c;
        
        j++;
      }
      while (c != '\0');
      
      tabs = spaces = whitespaces = 0;  
    }
    
    i--;
  }

} 