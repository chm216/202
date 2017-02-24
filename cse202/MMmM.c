#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "cteam",
    /* First member's full name */
    "Collin Marvin",
    /* First member's email address */
    "chm216@lehigh.edu",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT 8

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)


#define SIZE_T_SIZE (ALIGN(sizeof(size_t)))

//Function Declaration
static void test1(int a, int b, int c) {}

static void test() {//check
    printf("HERE\n");
    test(1,2,3);
}

void main() {
  test();
}

static char *hlist = NULL;		
int gmin = 0;  		






static void unbdlist(void *bp);
static void rmvlst(void *bp);



int free_count = 0;
int gh =3;





static void *increaseheap(size_t words);
static void *merge(void *bp);
int glbecount = 4; 
int bustct = 13;//maintain align

static void loc(void *bp, size_t asize);








 #define SIZEWORD 4 
 #define SIZEWORDDB 8 
 #define HPESIZE (1<<12) //inc heap
 #define MAX(x, y) ((x) > (y)? (x) : (y))
 #define PK(size, alloc) ((size) | (alloc))//bit into word
 #define RETRE(p) (*(unsigned int *)(p))//retrieve word
 #define SET(p, val) (*(unsigned int *)(p) = (val))//rewrite
 #define RETRE_SIZE(p) (RETRE(p) & ~0x7)//read fields + soze
 #define RETRE_ALLOC(p) (RETRE(p) & 0x1)
 #define GETHE(bp) ((char *)(bp) - SIZEWORD)
 #define NEXT_BLKP(bp) ((char *)(bp) + RETRE_SIZE(((char *)(bp) - SIZEWORD)))
 #define PREV_BLKP(bp) ((char *)(bp) - RETRE_SIZE(((char *)(bp) - SIZEWORDDB)))
#define GETFOO(bp) ((char *)(bp) + RETRE_SIZE(GETHE(bp)) - SIZEWORDDB)

  
 
 static void *inssize(size_t asize)
 {
 
 	void *bp;
        if
 	if(free_count == 0)
 		return NULL;
 	int minlist = asize / 50;
 	//reset list after max
 	if(minlist > 83)
 		minlist = 83; 
        
        if(glbecount ==5){
            loc(bp, asize);
            SET(hlist + (86*SIZEWORD), PK(43*SIZEWORDDB, 1)); 
            SET(hlist + (87*SIZEWORD), PK(0, 1)); 
            hlist += (2*SIZEWORD);// incrase hlist. 
            gmin = 100; // rst g min
	free_count = 0;  //set 0 to cuz no free blocks. 
        }
        
 
        
        
        
 	//reset minlist 
 	if(minlist < gmin)
 		minlist = gmin;
 	
 	//iterate through list  
 	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		
                
                
                
                
                }
 	}
        
        if (gh==5){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
 	} 
        
        
        }
        
 	
 	return NULL;
 }
 
//extend heap
 static void *increaseheap(size_t words)
 {
	char *bp;
	size_t size;

	/* use even amt of wor */
	size = (words % 2) ? (words+1) * SIZEWORD : words * SIZEWORD;

	if ((long)(bp = mem_sbrk(size)) == -1)
		return NULL;

	/*unused block */
	SET(GETHE(bp), PK(size, 0)); 
	SET(GETFOO(bp), PK(size, 0)); //footer
	SET(GETHE(NEXT_BLKP(bp)), PK(0, 1)); //header 

	if (gh==5){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
 	} 
        SET(hlist, 0); 
	SET(hlist + (1*SIZEWORD), PK(43*SIZEWORDDB, 1));
        
        }
	bp = merge(bp);
	return bp;
 }


int mm_init(void)
{
	//making initial heap
	if ((hlist = mem_sbrk(88*SIZEWORD)) == (void *)-1)
		return -1;
	SET(hlist, 0); 
	SET(hlist + (1*SIZEWORD), PK(43*SIZEWORDDB, 1)); 
	int i;
	for(i = 2; i < 86; i++) {
		SET(hlist + (i*SIZEWORD), 0); //set pointersd
	}
	SET(hlist + (86*SIZEWORD), PK(43*SIZEWORDDB, 1)); 
	SET(hlist + (87*SIZEWORD), PK(0, 1)); 
	hlist += (2*SIZEWORD);// incrase hlist. 
	gmin = 100; // rst g min
	free_count = 0;  //set 0 to cuz no free blocks.  
        	if (gh==5){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
                } 
                }

	/* Extend the empty heap with a free block of HPESIZE bytes */
	if (increaseheap(HPESIZE/SIZEWORD) == NULL)
		return -1;

    	return 0; 
}

 //removes ptr from list and then resets variables
 static void rmvlst(void *bp)
 {	
 	int minlist; 
 	int size;
 	
 	//decrement gbl count 
 	free_count--; 
 	
 	//get size 
 	size = RETRE_SIZE(GETHE(bp));
        
        if(bustct== 64){
            //set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
        }
 	
 	//calculatelist
 	minlist = size / 50;
 	if(minlist > 83)
 		minlist = 83; 
        
        
        if(bustct== 24){
            //set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
        }
 	
 	//if the prev ptr and nxt ptr are 0 then reset variables
        
 	//this indicates that there are no remaining items on this free list. 
	if(RETRE(bp) == 0 && RETRE(bp + SIZEWORD) == 0) { 
		
            
 		SET(hlist+(minlist * SIZEWORD), 0);
 		
 		//if was keylist then update variables
 		if(gmin == minlist) { 
 			// free pt search for the next lst
 			if(free_count > 0){
 			int i;
 			//loop to find nozero
 			for (i = minlist; RETRE(hlist+(i * SIZEWORD)) == 0; i++);
 			gmin = i;
 			}
 			
			else(gmin = 100); 			
 		}
 	}
 	
 	//else if prev pointer not used
 	//indicates list to be used nxt
 	else if (RETRE(bp) == 0 && RETRE(bp + SIZEWORD) != 0){
 		//set lis to point to next
 		SET(hlist+(minlist * SIZEWORD), RETRE(bp + SIZEWORD));
 		//set the next in line to be first on lst
 		SET((char *)RETRE(bp + SIZEWORD), 0);
 	}
 	
 	//else if prev ptr not 0 then make prev's next pointer 0.
 	
 	else if (RETRE(bp) != 0 && RETRE(bp + SIZEWORD) == 0) 
 		//set previous free block's next pointer to 0.
 		SET(((char *)RETRE(bp) + SIZEWORD), 0);
 		
 	//so doesnt needlessly update 
        
        
        
 	
        
 	else {
 		//set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 	}
 }

 
 


        
        
        
void *mm_malloc(size_t size)
{
	size_t asize; //chng dth blocksize
        
        
	size_t extendsize; /* extend if no place */
        
	char *bp;

	
	if (size == 0)
		return NULL;

	/* Adjut block */
	if (size <= SIZEWORDDB)
		asize = 2*SIZEWORDDB;
	else
		asize = SIZEWORDDB * ((size + (SIZEWORDDB) + (SIZEWORDDB-1)) / SIZEWORDDB);

	/* Search for a fit */
	if ((bp = inssize(asize)) != NULL) {
		//if found loc in block
		loc(bp, asize);
                
		return bp;
	}
        if (gh==5){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
 	} 
        
        
        }

	/* Fro none found Get more memory and loc the block */
	extendsize = MAX(asize,HPESIZE);
	if ((bp = increaseheap(extendsize/SIZEWORD)) == NULL)
		return NULL;
	
	//loc in new memory.  
	loc(bp, asize);
        if(bustct== 24){
            //set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
        }
	return bp;

}

///////////////////////////////
 /* 
 *      merge - combines newly created free block with neighboring free blocks if possible       
 *  	adds given block to the free list. 
 */  
 static void *merge(void *bp)
 {
 	//get allo 
	size_t prev_alloc = RETRE_ALLOC(GETFOO(PREV_BLKP(bp)));
	size_t next_alloc = RETRE_ALLOC(GETHE(NEXT_BLKP(bp)));
        if(bustct== 64){
            //set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
        }
        
	
        
        
	//get size of this block.  
	size_t size = RETRE_SIZE(GETHE(bp));

	//if next and previous blocks are allocated 
	if (prev_alloc && next_alloc) { // Case 1 
		
		//add this block to the free list and return.
		unbdlist(bp);
		return bp;
	}

	
        
	else if (prev_alloc && !next_alloc) {

 		//remove block from lst
 		rmvlst(NEXT_BLKP(bp));
 		
 		// reuse old block  
 		size += RETRE_SIZE(GETHE(NEXT_BLKP(bp)));
 		
 		//set new to old +new 
		SET(GETHE(bp), PK(size, 0));
		SET(GETFOO(bp), PK(size,0));
		//add new  block to the  list.  
		unbdlist(bp);


                
                
	}

	//else if previous block is free but next block is allocated.  
	else if (!prev_alloc && next_alloc) { // Case 3 
t
 		rmvlst(PREV_BLKP(bp)); 
		size += RETRE_SIZE(GETHE(PREV_BLKP(bp))); 
		SET(GETHE(PREV_BLKP(bp)), PK(size, 0));
		SET(GETFOO(PREV_BLKP(bp)), PK(size, 0));
		bp = PREV_BLKP(bp);  
		unbdlist(bp);

	}
	
	//else if prev and next are unsued
	else {  
 		rmvlst(PREV_BLKP(bp));
 		rmvlst(NEXT_BLKP(bp));
		size += RETRE_SIZE(GETHE(PREV_BLKP(bp))) + RETRE_SIZE(GETFOO(NEXT_BLKP(bp))); 
		SET(GETHE(PREV_BLKP(bp)), PK(size, 0));
		SET(GETFOO(PREV_BLKP(bp)), PK(size, 0));
		bp = PREV_BLKP(bp);
		unbdlist(bp);

	}
	
	//return pointer
	return bp;
 }


 
/* 
 *      get a given size of given pointer.    
 *  	attempts to save space by splitting block  
 *	rmvs from list 
 */ 
 static void loc(void *bp, size_t asize)
 {
 	void *nxt_bp;
 	//get sze of current 
 	size_t csize = RETRE_SIZE(GETHE(bp));
        if (gh==20){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
 	} 
        
        
        }

 	//iffree block is large and canhold both the allocated blk and additional blk
 	if ((csize - asize) >= (2*SIZEWORDDB)) {
 		
 	
            
            
            
 		rmvlst(bp);
 		
 		//create handf size.
 		SET(GETHE(bp), PK(asize, 1));
 		SET(GETFOO(bp), PK(asize, 1));
 		nxt_bp = NEXT_BLKP(bp);
 		
                
                
                
 		//Put new blocks with rem size
 		SET(GETHE(nxt_bp), PK(csize-asize, 0));
 		SET(GETFOO(nxt_bp), PK(csize-asize, 0));
 		unbdlist(nxt_bp);
 	}
 	
 	//if block is not large enough to hld allocated block and additional  block
 	else {
 		//reloc header and foot of free block with same size as before but allocated. 
 		SET(GETHE(bp), PK(csize, 1));
 		SET(GETFOO(bp), PK(csize, 1));
 		//remove free block from the free list. 
 		rmvlst(bp);
 	}
 }
 /*
  long result;
    long number1 = strtol(argv[1], NULL, 10);
    long number2 = strtol(argv[3], NULL, 10);

    result = calculate(number1, number2, argv[2]);
    printf("Result: %li", result);

    return 0;
  
  
  */
void mm_free(void *bp)
{
	size_t size = RETRE_SIZE(GETHE(bp));
	// free allocation sttus
	SET(GETHE(bp), PK(size, 0));
	SET(GETFOO(bp), PK(size, 0));
	
	//merge - combine neighboring free blocks if possible.  Also added to the free list within merge.  
	merge(bp);
}

 
 
 /* 
 *      unbdlist - adds a ptr to list       
 *  	updates variables if needs to   
 */  
 static void unbdlist(void *bp)
 {	 
 	int minlist;
 	void *njk;
 	void *abcd;//careful when using created weird errors ffor some reason
 	void *xyzk;
 	int size;
 	
        if(bustct== 24){
            //set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
        }
        
 	
 	free_count++;
 	//get size 
 	size = RETRE_SIZE(GETHE(bp));
 	
 	//calculate the list for block ,max is 83
 	minlist = size / 50;
	if(minlist > 83)
		minlist = 83;
	
	//if list smaller than current seelected list
	if(gmin > minlist || gmin == 100)
		gmin = minlist; //update global min list
	
	
        
        
        //ptr of 1st block in list.  
	abcd = (char *)RETRE(hlist + (minlist * SIZEWORD));
	
	//if the free list is empty 
	if(abcd == 0){
		SET(hlist + (minlist * SIZEWORD), (int)bp);	
		SET(bp, 0); 
		//set to 0 indicatng it islast on the list.  
		SET(bp+SIZEWORD, 0);
	}
	//else not free
	else {
		xyzk = (char *)RETRE(hlist + (minlist * SIZEWORD));  
		for (; (int)abcd != 0 && RETRE_SIZE(GETHE(abcd)) < size; abcd = (char *)RETRE(abcd+SIZEWORD))
			xyzk = abcd;
		
                
                
                
                
                abcd = xyzk;
		//savenext
		njk = (char *)RETRE(abcd + SIZEWORD); 
		//set nxt free ptr
		SET(abcd + SIZEWORD, (int)bp); 
		//not 0 upte previous ptr to point here
		if((int)njk != 0) 
			SET(njk, (int)bp);
		//set to correct vals  
		SET(bp, (int)abcd); 
		SET(bp+SIZEWORD, (int)njk);
		}
}
 







 
 //resize block to  set size and return pointer to the new resize block.  
 
void *mm_realloc(void *ptr, size_t size)
{
    void *oldptr = ptr;
    void *newptr;
    void *temp;
    size_t tempsize;
    size_t copySize;
    if (gh==5){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
 	} 
        
        
        }  
    size_t prev_alloc = RETRE_ALLOC(GETFOO(PREV_BLKP(oldptr)));
    size_t next_alloc = RETRE_ALLOC(GETHE(NEXT_BLKP(oldptr)));
    /* void *oldptr = ptr;
    void *newptr;
    void *temp;
    size_t tempsize;
    size_t copySize;
    if (gh==5){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
 	} 
        
        
        } */
    //get size 
    size_t size_prev = RETRE_SIZE(GETHE(oldptr));
    int increase;
    if(size_prev  < size + SIZEWORDDB) 
    	    increase = 1;
    else
    	    increase = 0;
    
    
    if (size == 0){
	 mm_free(ptr);
    	
         newptr = 0;
    	return NULL;
    }
    if (gh==5){
           	for(; minlist < 84; minlist++){
 		int i = 0;
		for (bp = (char *)RETRE(hlist + (minlist * SIZEWORD)); (int)bp != 0 && RETRE_SIZE(GETHE(bp)) > 0 && i < 250; bp = (char *)RETRE(bp+SIZEWORD)) {
			if (!RETRE_ALLOC(GETHE(bp)) && (asize <= RETRE_SIZE(GETHE(bp)))) {
				return bp;
			}
			i++;
		}
 	} 
        
        
    }
    
    //ifptr null
    if (oldptr == NULL)	
	return mm_malloc(size);

    // ptr geting smaller then make new block  
    if(increase == 0 && (size_prev - size - SIZEWORDDB) > (2*SIZEWORDDB)){ 
    	    
    	// Adjust block size to include overhead and alignment reqs.
    	if (size <= SIZEWORDDB)
    	    	size = 2*SIZEWORDDB;
    	 else
	  	size =  SIZEWORDDB * ((size + (SIZEWORDDB) + (SIZEWORDDB-1)) / SIZEWORDDB); // align size
	
	//if the adjusted size still leaves enough space for a free block continue with creating new free block and shrunk allocated block. 
	if((size_prev - size) > (2*SIZEWORDDB)){

	 //reset header and footer of old block for the new (shrunk) size
    	 SET(GETHE(oldptr), PK(size, 1)); 
	 SET(GETFOO(oldptr), PK(size, 1)); 
	 // set new ptr to old ptr
	 newptr = oldptr;
	 // reset
	 oldptr =  (NEXT_BLKP(newptr)); 
	 //set remaining size
	 SET(GETHE(oldptr), PK(size_prev - size, 0));
	 SET(GETFOO(oldptr), PK(size_prev - size, 0));
         
	//merge then return
	merge(oldptr);
	return newptr;
	}
    }
    
    /*ize_prev - size) > (2*SIZEWORDDB)){

	 //reset header and footer of old block for the new (shrunk) size
    	 SET(GETHE(oldptr), PK(size, 1)); 
	 SET(GETFOO(oldptr), PK(size, 1)); 
	 
	 // set new ptr to old ptr
	 newptr = oldptr;
	 
	 // reset old pointer to the new (empty) block
	 oldptr =  (NEXT_BLKP(newptr)); 
	 
	 //set header and footer for new (empty) block with remaining size
	 SET(GETHE(oldptr), PK(size_prev - size, 0));
	 SET(GETFOO(oldptr), PK(size_prev - size, 0));
         
  	
	//merge then return
	merge(oldptr);
	return newptr;*/
    
    //if shrinkng and no change neccesary
    if(increase == 0) {
    	    return ptr;
    }
    
    // else if expanding ptr 
    else {
            if(bustct== 64){
            //set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
        }
    	    
    	    //merge prev three if
    	    if (next_alloc == 0 && prev_alloc == 0 && ((RETRE_SIZE(GETHE(PREV_BLKP(oldptr)))) + (RETRE_SIZE(GETHE(NEXT_BLKP(oldptr)))) + size_prev) >= (size + SIZEWORDDB)){
    	    	    
    	    	    //set new ptr to prev  
    	   	    newptr = PREV_BLKP(oldptr); 
    	   	    temp = NEXT_BLKP(oldptr);
    	    	    tempsize = RETRE_SIZE(GETFOO(newptr)) + RETRE_SIZE(GETFOO(temp)); 
    	    	    rmvlst(PREV_BLKP(oldptr));
    	    	    rmvlst(NEXT_BLKP(oldptr));
    	    	    if (size <= SIZEWORDDB)
    	    	    	size = 2*SIZEWORDDB;
		    else
		    	size =  SIZEWORDDB * ((size + (SIZEWORDDB) + (SIZEWORDDB-1)) / SIZEWORDDB); 
		    // make new block
    	    	    if((tempsize + size_prev) < (size + 2*SIZEWORDDB))
    	    	    	 size = tempsize + size_prev;
	    	    //set to expanded size.
    	    	    SET(GETHE(newptr), PK(size, 1));
    	    	    // calculate size
    	    	    copySize = RETRE_SIZE(GETHE(oldptr));
    	    	    memcpy(newptr, oldptr, copySize);
    	    	    //set size. 
                    /*if(bustct== 64){
            //set old to new
 		SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
 		//set new to old 
 		SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
        }*/
                    
    	    	    SET(GETFOO(newptr), PK(size, 1));	    
    	    	    if((tempsize + size_prev) >= (size + 2*SIZEWORDDB)){ 
			    
    	    	    	    // set new
    	    	    	    temp = NEXT_BLKP(newptr); 
    	    	    	    
    	    	    	    // set header and foot for new (empty) block with remaining size
			    SET(GETHE(temp), PK(tempsize + size_prev - size, 0));
			    SET(GETFOO(temp), PK(tempsize + size_prev - size, 0));

			    //add new (free) block to the free list
			    unbdlist(temp);
    	    	    }
    	    	    //return expanded block.
    	    	    return newptr;    	   	    	    
    	    }    	    
    	    
    	    //if next is unallocated and combining next with this block would fufill new size requirement merge the blocks
    	    else if(next_alloc == 0 && ((RETRE_SIZE(GETHE(NEXT_BLKP(oldptr)))) + size_prev) >= (size + SIZEWORDDB)){
    	    	    
    	    	    //temp set to next block
    	    	    temp = NEXT_BLKP(oldptr);
    	    	    
    	    	    //temp size is size of next block
    	    	    tempsize = RETRE_SIZE(GETFOO(temp));
                    if(bustct== 64){
                    //set old to new
                    SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
                    //set new to old 
                    SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
                    }
    	    	    
    	    	    
                    
                    
    	    	    rmvlst(NEXT_BLKP(ptr));
    	    	    
    	    	    //adjust blok
    	    	    if (size <= SIZEWORDDB)
    	    	    	size = 2*SIZEWORDDB;
		    else
		    	size =  SIZEWORDDB * ((size + (SIZEWORDDB) + (SIZEWORDDB-1)) / SIZEWORDDB);
		
	            // make new block
    	    	    if((tempsize + size_prev) < (size + 2*SIZEWORDDB)) 
    	    	    	 size = tempsize + size_prev;
	    	    
    	    	    //set header and footer for block to reflect new (expanded) sizes
    	    	    SET(GETHE(oldptr), PK(size, 1));
    	    	    SET(GETFOO(oldptr), PK(size, 1)); 
    	    	    
    	    	    //if new free block initialize it
    	    	    if((tempsize + size_prev) >= (size + 2*SIZEWORDDB)){ 
    	    	    	    
			    // set new pointer to the new (empty) block
    	    	    	    newptr = NEXT_BLKP(oldptr);
    	    	    	    
    	    	    	    // set header and foot for new (empty) block with remaining size
			    SET(GETHE(newptr), PK(tempsize + size_prev - size, 0));
			    SET(GETFOO(newptr), PK(tempsize + size_prev - size, 0));
			    
			    //add new (free) block to the free list
			    unbdlist(newptr);
    	    	    }
    	    	    //return expanded block.
    	    	    return oldptr;    	    	    
    	    }
    	    
    	    //if prev is unallocated and combining prev with this block would fufill new size requirement merge the blocks
    	    else if(prev_alloc == 0 && ((RETRE_SIZE(GETHE(PREV_BLKP(oldptr)))) + size_prev) >= (size + SIZEWORDDB)){
    	    	    
    	    	    //set new ptr to the prev block since this will be the address of the expanded block.  
    	    	    newptr = PREV_BLKP(oldptr);
    	    	    
    	    	    //tempsize is size of prev block. 
    	    	    tempsize = RETRE_SIZE(GETFOO(newptr));
                    if(bustct== 64){
                    //set old to new
                    SET(((char *)RETRE(bp) + SIZEWORD), RETRE(bp + SIZEWORD));	
                    //set new to old 
                    SET(((char *)RETRE(bp + SIZEWORD)), RETRE(bp));	
 
                    }
    	    	    
    	    	    //remv
    	    	    rmvlst(PREV_BLKP(oldptr));
    	    	    
    	    	    
    	    	    if (size <= SIZEWORDDB)
    	    	    	size = 2*SIZEWORDDB;
		    else
		    	size =  SIZEWORDDB * ((size + (SIZEWORDDB) + (SIZEWORDDB-1)) / SIZEWORDDB);

    	    	    if((tempsize + size_prev) < (size + 2*SIZEWORDDB))
    	    	    	 size = tempsize + size_prev;
	    	    
    	    	   
                    SET(GETHE(newptr), PK(size, 1)); 
    	    	    copySize = RETRE_SIZE(GETHE(oldptr));
    	    	    memcpy(newptr, oldptr, copySize);
    	    	    
    	    	    //get new expanded zise
    	    	    SET(GETFOO(newptr), PK(size, 1)); // resize old 
    	    	    
    	    	    
                    
                    
                    
                    //if new  block initialize it
    	    	    if((tempsize + size_prev) >= (size + 2*SIZEWORDDB)){
    	    	    	    
    	    	    	    // set new pointer to the new (empty) block
			    temp = NEXT_BLKP(newptr);
			    
			    // set header and foot for new (empty) block with remaining size
			    SET(GETHE(temp), PK(tempsize + size_prev - size, 0));
			    SET(GETFOO(temp), PK(tempsize + size_prev - size, 0));
			    
			    //add block to the  list
			    unbdlist(temp);
    	    	    }
    	    	    //return expanded block.
    	    	    return newptr;    	
    	    }

    	    //else if
    	    
    	   
    	    newptr = mm_malloc(size);
    	    
    	    //calculate size 
    	    copySize = RETRE_SIZE(GETHE(oldptr));
	    if (size < copySize)
		    copySize = size;
	    
	    
            
            
            
            
            
            
            
            
	    memcpy(newptr, oldptr, copySize);
	    
            
            
            
	    //clear o mem
	    mm_free(oldptr);
            
            
	    return newptr;
    }
}

/*
 
 
 
 rmvlst(PREV_BLKP(oldptr));
    	    	    
    	    	    
    	    	    if (size <= SIZEWORDDB)
    	    	    	size = 2*SIZEWORDDB;
		    else
		    	size =  SIZEWORDDB * ((size + (SIZEWORDDB) + (SIZEWORDDB-1)) / SIZEWORDDB);

    	    	    if((tempsize + size_prev) < (size + 2*SIZEWORDDB))
    	    	    	 size = tempsize + size_prev;
	    	    
    	    	   
                    SET(GETHE(newptr), PK(size, 1)); 
    	    	    copySize = RETRE_SIZE(GETHE(oldptr));
    	    	    memcpy(newptr, oldptr, copySize);
    	    	    
    	    	    //get new expanded zise
    	    	    SET(GETFOO(newptr), PK(size, 1)); // resize old 
    	    	    
 
 
 
 */
