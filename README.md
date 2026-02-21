# Arabic Morphological Engine

A C++ command-line application that implements an Arabic morphological engine based on the **root–pattern system**.

The project uses:
- An AVL tree to store triliteral Arabic roots  
- A hash table to store morphological patterns  
- A derivation engine to generate and validate Arabic words  

It allows users to load roots, generate derived words, and verify if a word belongs to a given root.

---

## ▶️ Run Instructions

```bash
git clone https://github.com/rahmakal/arabic-morphological-engine.git
cd arabic-morphological-engine

mkdir build
cd build

cmake ..
make

./arabic-morphological-engine
