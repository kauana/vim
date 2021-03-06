Vim�UnDo� �_8���Rƨ������J ���J��k�u��  (                                   Z�u�    _�                             ����                                                                                                                                                                                                                                                                                                                                                 V        Z�u�     �                # Project #4 - File Systems   ## fs_mount   LIn this function, we used block_disk_open with diskname and block_disk_count   #to confirm that we opened the file:   Bif (block_disk_open(diskname) == -1 || block_disk_count() == -1) {       OFor this part, we also needed to malloc a new disk with elements for the layout   Mof our disk in which we made a struct for, such as for the fat, files_count,    Nfile_descriptors, root_directory, and the superblock. For each of the structs,   Mwe used the library <stdint.h> for the uint integer types, to ensure that the   Ndata we are reading in for each segment of a block is the right size in bytes.   LWe then used block_read to populate our disk space with the appropriate data   Lblocks, such as: block_read(0, disk->superblock) to populate the superblock.   NIf we weren't able to read a block that we needed, we would call fs_cleanup();   OWe read the corresponding blocks of data for the fat, and root directory in the   Ivirtual disk. After that we calculated the count of how many files in the   Ndisk were free for the root director for fs_info, we did that with a for loop    and an if statement:   -for (int i = 0; i < FS_FILE_MAX_COUNT; i++) {   Y        if (strlen_s(disk->root_directory[i].filename, FS_FILENAME_LEN) != 0) {files++;}}   Nwe did a similar method for calculating the amount of free fat blocks remained   Hfor the disk: for (int i = 0; i < disk->superblock->total_blocks; i++) {   &        if (disk->fat[i].entry != 0) {               blocks++;}    J            disk->fat_free_blks = disk->superblock->total_blocks - blocks;       ##fs_cleanup   Ifs_cleanup is a helper function that closes the virtual disk that we were   Kworking with, and free's up the disk structure we made in fs_mount. A short   2snippet of the code to free the disk structure is:   !    free(disk->file_descriptors);       free(disk->root_directory);       free(disk->superblock);   %    if (disk->fat) {free(disk->fat);}       free(disk);       disk = NULL;       ##fs_umount   NFor this function, we needed to write back our disk structure we made in mount   1to the virtual disk, so that we save our changes.   LWe checked if the disk was open and if there was any remaining files opened,   >and if these if statements were true we would return an error:   if (disk == NULL);   if (disk->files_count > 0)       PWe then write the superblock back to the virtual disk, and if there was an error   we would return -1:   ;    if (block_write(0, disk->superblock) == -1){return -1;}       MWe also had to write the FAT entries back to virtual disk, we did this with a   Nfor loop, we also had an offset to make sure we continued to move to the next    data block: size_t offset = 0;   7for (int i = 0; i < disk->superblock->total_fat; i++) {   2        if (block_write(i + 1, disk->fat) == -1) {               return -1;}   @        //write 1 block (4096 bytes) as FAT objects = 2048 bytes   8        offset += BLOCK_SIZE / sizeof(struct fat_entry);       }       OWe would finally write back the root_directory entries back to the virtual disk   with block_write:    Vif (block_write(disk->superblock->rdb_index, disk->root_directory) == -1) {return -1;}       QAfter that we would call our fs_cleanup() function to free our code from earlier.       	##fs_info   LThis function prints out certain info on the disk we are working on, such as   Nthe total block count, fat block count, root directory, and so on. It did this   9by just printing out the data we stored in disk, such as:   >    printf("total_blk_count=%d\n", disk->superblock->b_total);       ##has_filename   PIs a helper function that checks if the root_directory array has a file with the   Mfilename passed as an argument. Does so with a for loop that goes through the   Oroot directory and compares the strings for each entry until the same filename    
is found:    -for (int i = 0; i < FS_FILE_MAX_COUNT; i++) {   F        if (strcmp(filename, disk->root_directory[i].filename) == 0) {               return i;}}       ##fs_create   QTo create a new file, first we had to check if the filename given was valid with:   >    if (strlen_s(filename, FS_FILENAME_LEN) == 0) {return -1;}   KIf it was we then checked if the file was already in our root directory, by   Mcalling a helper function called has_filename, if it did then we would return   Man error. After that, we had to find an empty entry in the root directory, in   Pwhich we used a for loop to check the names of the entries in the root directory   Nif any of them were empty then that index was available, if not then we can't    2add any: for (i = 0; i < FS_FILE_MAX_COUNT; i++) {   O        if (strlen_s(disk->root_directory[i].filename, FS_FILENAME_LEN) == 0) {               break;}}   EAfter that, we create a new empty file in the index we found for the    7root_directory, and add the appropriate fields such as:   (    strcpy(newFile->filename, filename);       newFile->file_size = 0;   !    newFile->fdb_index = FAT_EOC;       ##fs_delete   IThis function deletes a file by first finding the file with has_filename,   which   Jreuturns where in the root directory the file is, then we use a while loop   'to delete the filename's data from FAT:   >    int fat_index = disk->root_directory[to_delete].fdb_index;       int temp;   4    while (fat_index != FAT_EOC && fat_index != 0) {   I        temp = disk->fat[fat_index].entry; // save next file part's index   =        disk->fat[fat_index].entry = 0;    // clean fat entry   C        fat_index = temp; // fat_index now holds the next file part       }   JAfter that we clear out the rest of the data for the root directory entry.       ##fs_ls   OLists files in the root directory by using a for-loop and for each valid entry    Nit finds (it checks the filename for valid names) it prints out the filename,    $size, and data block for each file:    K    printf("file: %s, size: %d, data_blk: %d\n", filename, size, data_blk);       ##available_fd   MChecks if there is an available space to create a new file descriptor in the    Odisk->file_descriptors array. Does so by checking the amount of files open, and   'using a for loop to find an open entry.       	##fs_open   KWhen opening a file, after checking if the disk and name is valid, it finds   Lwhere the file is using the has_filename function we used earlier, and using   Lthe available_fd to find a new file descriptor for the file. After that, it    Nmakes a new file descriptor which is stored in our disk file descriptor array,   Mand sets the offset to zero and file desciptor with the index we need for it:   G    struct file_descriptor *new_fd = &disk->file_descriptors[fd_index];       new_fd->offset = 0;       new_fd->fd = fd_index;   IAfter that, we put the file_entry we wanted into the file descriptor and    Nincrement our files count for how many files we have open, then return the new   file descriptor:   -    int entry_index = has_filename(filename);   <    new_fd->file_entry = &disk->root_directory[entry_index];       disk->files_count++;       return fd_index;       
##fs_close   EFirst we check if the disk is open, and if the fd passed in is valid:   9    if (disk == NULL || fd > FS_OPEN_MAX_COUNT || fd < 0)   Ithen we check if the file descriptor were given is populated, if it isnt    return error:   A    if (disk->file_descriptors[fd].file_entry == NULL{return -1;}   KThen we clear out the file descriptor we have to make space for a new file:   1    disk->file_descriptors[fd].file_entry = NULL;   *    disk->file_descriptors[fd].offset = 0;       disk->files_count--;       	##fs_stat   QCheck of a file descriptor is valid, much as we did in the beginning of fs_close.   2Then return file size if file descriptor is valid:   <    return disk->file_descriptors[fd].file_entry->file_size;       
##fs_lseek   KIf a file descriptor is valid, check if the offset is within bounds, if not   return error:    Kif (offset > disk->file_descriptors[fd].file_entry->file_size) {return -1;}   If valid, update offset:   /    disk->file_descriptors[fd].offset = offset;       ##first_fit   NHelper function that finds the first block in the FAT array that is free. Does   Kthat by running a for loop, if an entry points to 0, then it is free, then    we return that free index:       int fit = 0;   >    for (int i = 0; i < disk->superblock->total_blocks; i++) {   -        if (disk->fat[i].entry == 0) {break;}           fit++;       }   ;    if (fit == disk->superblock->total_blocks) {return -1;}       return fit;       ##find_index   NFinds the index of the data block corresponding to the given offset, datablock   Nstart from the superblock, and the first data block index given from the file    Oentry. We first check how many blocks the offset will take up, we did this with   Na while loop, decrementing the offset by a block each time it was bigger than    La block, and checking if the next fat entry was valid, and updating our data   /block index with the entry we found in the fat:   "    while (*offset > BLOCK_SIZE) {   7    if (disk->fat[index].entry == FAT_EOC) {return -1;}   '        index = disk->fat[index].entry;           *offset -= BLOCK_SIZE;       }       NAfter we accouted for the offset, we took the index we have at the current FAT   Mentry, and then added it with the datablock start to find the exact location    0of the datablock we want, and return that index:       index += dbs_index;       return index;           ##fs_write_once   MTo write to a block, we first read the block we want to write to and store it   in a bounce buffer:   #    char bounce_buffer[BLOCK_SIZE];   2    if (block_read(index, bounce_buffer) == -1)...       JWe then find out how much we want to write, we do this by checking the min   Mbetween our count and the blocksize + offset, that way if the count is bigger   Mthan a block then we would write a block, otherwise we would write the count:   3    int to_write = MIN(count, BLOCK_SIZE - offset);   OWe then use memcpy to copy what we have in our buffer to our bounce_buffer with   the amount for to_write:   4    memcpy(bounce_buffer + offset, buffer, to_write)   CAfter that, we write the bounce buffer back to the data block with:   &    block_write(index, bounce_buffer);   !Then we return how much we wrote.       
##fs_write   LFor write, after we check if the disk and file descriptor is valid, we check   Kif this is the first write to the file, if it is we need to make a new FAT    Mentry. We do this with calling first_fat(fd), and what it returns will be our   Ofirst fat entry, in which we can find the datablock we can write to. Now we can   Nwrite to the file, we use a while loop while we still have a count of bytes we   Lwant to write, then we use find_index to find the block we want to write to,   Oand use our helper function fs_write_once to write to the block. After we wrote   Oto the block, we store the amount of blocks we wrote to an integer called wrote   #if it is -1, then an error occured:   @        int wrote = fs_write_once(index, count, offset, buffer);           if (wrote == -1) {               return total;}   Mafter that, we remove the bytes we wrote from count, move our buffer forward,   Land increment our total bytes written to be returned later. If we expand the   Iamount of bytes we had in our file, we would need to increment our file's   variable for file_size:   B    int file_space = offset;... (declared before the while loop)         file_space += wrote;   #    if(file_space > fe->file_size){       fe->file_size += wrote;}   NAfter that we set offset to 0, since we no longer need it, and if we have more   Lblocks to write to, we check if our entry in FAT has another block linked in   Owhich we can use, and if it doesn't, then we find a new available block and use   Gthat for future writes and store that back in our fat entry to link it:   0    if (disk->fat[fdb_index].entry == FAT_EOC) {   '        int next_block = first_fit(fd);           if (next_block == -1) {               return total;}   5            disk->fat[fdb_index].entry = next_block;}   LAfter we are done with the while loop, we return the total amount of blocks    	we wrote.       	##fs_read   IAfter we check if the disk and fd were valid, we get the first index with   Mfind_index, after that we check if we want to read a segment of a file, if we   Mdo we use a bounce buffer and read that block, then use memcpy to copy it to    the buffer, then return:   "    char bounce_bufer[BLOCK_SIZE];   .    block_read(db_index, bounce_bufer) == -1);   .    void *curr_offset = bounce_bufer + offset;   0    memcpy(buffer, curr_offset, count) != NULL);   Mif we want to read more than one block, and we have a offset, we then have to   Lread mid-block, to do this we use a bounce buffer again, and read that block   ;then copy the portion we want into the buffer using memcpy:   7    memcpy(buffer, curr_offset, (BLOCK_SIZE - offset));   Lwe keep track of the position so that future calls to memcpy knows where to    Kcopy into the buffer. We then use a while loop for the inside blocks, where   Lif the count is larger than a block, we copy the block into a bounce buffer,   Lthen copy that into our buffer, also accounting for where to start with our    copy before:   :    memcpy((buffer + position), bounce_bufer, BLOCK_SIZE);   OWe then search for the next datablock index to copy with checking what the next   Fentry in the FAT table is and using find_index to find the next index:   +    fdb_index = disk->fat[fdb_index].entry;   9    db_index = find_index(fdb_index, dbs_index, &offset);   NAfter the while loop, if we have a count left, then that means that we need to   Kread a portion of a final block, we do this with yet again a bounce buffer,   Hand using block_read to store the data into the bounce buffer, and using   %memcpy to store that into the buffer.   QWe return position, which is a variable that kept cout of how much bytes we read.       #### Reources   e[The GNU C library](https://www.gnu.org/software/libc/manual/html_mono/libc.html "The GNU C library")5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        Z�u�     �                   5�_�                            ����                                                                                                                                                                                                                                                                                                                                                  V        Z�u�     �                  OB5�_�                    )        ����                                                                                                                                                                                                                                                                                                                                                  V        Z�u�    �  (  )          OB5��