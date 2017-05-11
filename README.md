<h1 align="center">Huffman code</h1>
In computer science and information theory, a Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression. The process of finding and/or using such a code proceeds by means of Huffman coding, an algorithm developed by David A. Huffman while he was a Sc.D. student at MIT, and published in the 1952 paper "A Method for the Construction of Minimum-Redundancy Codes".[1]

The output from Huffman's algorithm can be viewed as a variable-length code table for encoding a source symbol (such as a character in a file). The algorithm derives this table from the estimated probability or frequency of occurrence (weight) for each possible value of the source symbol. As in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. Huffman's method can be efficiently implemented, finding a code in time linear to the number of input weights if these weights are sorted.[2] However, although optimal among methods encoding symbols separately, Huffman coding is not always optimal among all compression methods.

Specifically, Huffman coding is optimal only if the probabilities of symbols are natural powers of 1/2. This is usually not the case. As an example, a symbol of probability 0.99 carries only {\displaystyle \log _{2}(1/0.99)\approx 0.014} {\displaystyle \log _{2}(1/0.99)\approx 0.014} bits of information, but Huffman coding encodes each symbol separately and therefore the minimum length for each symbol is 1 bit. This sub-optimality is repaired in arithmetic coding and recent faster Asymmetric Numeral Systems family of entropy codings.

<p align="right"><a href="https://en.wikipedia.org/wiki/Huffman_coding">More information</a></p>
<br><br><br><br>
<img src="https://github.com/dxbluff/Huffman/blob/master/Huffman_huff_demo.gif" alt="vis_huffman_code" align="center">
<br><br><br>
