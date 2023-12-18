import itertools

class Scs:
    def __init__(self, file):
        self.file = file

    def preprocessing(self):
        seq_lst = []
        fseq = []
        x = open(self.file)
        for line in x:
            if line.startswith('A') or line.startswith('T') or line.startswith('G') or line.startswith('C'):
                seq_lst.append(line)
        for seq in seq_lst:
            k = seq.strip()
            fseq.append(k)
        return fseq

    def overlap(self, a, b):
        start = 0 
        while True:
            start = a.find(b[:1], start)
            if start == -1:
                return 0
            if b.startswith(a[start:]):
                return len(a) - start
            start += 1

    def maximum_overlap(self, reads):
        reada, readb = None, None
        best_overlaplen = 0
        for a, b in itertools.permutations(reads, 2):
            overlaplen = self.overlap(a, b)
            if overlaplen > best_overlaplen:
                reada, readb = a, b
                best_overlaplen = overlaplen
        return reada, readb, best_overlaplen

    def greedyscs(self):
        reads = self.preprocessing()
        read_a, read_b, overlaplen = self.maximum_overlap(reads)
        while overlaplen > 0:
            reads.remove(read_a)
            reads.remove(read_b)
            reads.append(read_a + read_b[overlaplen:])
            read_a, read_b, overlaplen = self.maximum_overlap(reads)
            res= ''.join(reads)
    
    
        with open ("assembled_genome.txt", "w") as f:
            f.write(res)
        f.close()

        return "The genome assembly generated successfully in plain text format in a text file in the current directory [file name: assembled_genome.txt].\nNOTE: Call getAssembledGenomeLength function to get the length of assembled genome.\nNOTE: Call plainText2FASTA function for get the assembly in fasta format.\n"


    # def getAssembledGenomeLength (self):
    #     try: return f"Assembled genome length-> {len(self.scs)}\n"
    #     except:
    #         return "The genome is not assembled. First assembled the genome by calling assembly function. Then call getAssembledGenomeLength function.\n"


    # def plainText2FASTA(self):
    #     try:
    #         with open ("assembled_genome.fasta", "w") as f:
    #             f.write(">assembled_genome\n")
    #             count = 1
    #             for i in self.scs:
    #                 f.write(i)
    #                 if count%70 == 0: f.write("\n")
    #                 count += 1
    #         f.close()
    #         return "The genome assembly converted successfully from plain text format to FASTA format [file name: assembled_genome.fasta].\n"
    #     except:
    #         return "The genome is not assembled. First assembled the genome by calling assembly function. Then call plainText2FASTA function.\n"



output = Scs('mv.fastq')
result = output.greedyscs()
print(result)
print(len(result))
