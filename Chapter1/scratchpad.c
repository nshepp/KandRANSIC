
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






int iswhitespace(char c)
{
  if (c==' ' || c=='\b' || c=='\t'|| c=='\n')
    return 1;
  else
    return 0;
}

void trimline(char s[], int len)
{
  int i;
  
  for (i=len-1; i>=0; i--)
  {
    if (iswhitespace(s[i]))
      s[i] ='\0';
    else
      break;
  }
}




/* break lines */
i = 0;
while (s[i]!='\0') 
{
  c = s[i];
  
  if ((i+1)%wrap_col == 0)
  {
    if (s[i+1] == '\0')
    {
      return;
    }
    else if (isblank(c))
    {
      /* if blank, put newline char after moving 1 space */ 
      if (isblank(s[i+1]))
      {
       /* insert new line after deleting extraneous blanks */ 
        
      }
      else
      {
        /* go to left to remove spaces */
        
        
      }  
    }
    else
    {
      /* if char, either enter new line if blank after moving 1, or hyphenate and move 2 spaces for new line */ 
      
    }
    
    if (isblank(c))
      s[i] = '\n';
    else
        
      
  i++;
}



   
  
  
  
  
  
  
  /* Finds string length 'len' */
  len = 0;
  while (s[len]!='\0') len++;
  
  if (len < wrap_col) 
    return;
  else 
  {
    if (c!=' ' || c!='\t')
    {
      /* move word along 2 characters to place hyphen and newline char */
      i = len;
      do
      {
        c = s[i];
        
        s[i+2] = c;
        
        i--;
      }
      while (i>=wrap_col);
      
      s[wrap_col] = '-';
      s[wrap_col+1] = '\n';

    }  
  }  
}






int i = 0, idx = 0, lastchar = 'A';

do
{
  c = s[i];
  
  if (!isblank(c))
    idx = i;
  else
    s[idx] = c;
  
  i++;
}
until (c == '\0') 
