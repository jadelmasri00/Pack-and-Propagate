**Pack and Propagate, An Improved Blockchain Consensus Algorithm**

This repository hosts the research paper:

“Pack and Spread: An Improved Blockchain Consensus Algorithm”
(See Pack_and_Propagate.pdf for the full text.)

**Overview**

Consensus algorithms are at the heart of blockchain systems, ensuring participants agree on the validity of transactions and the state of the distributed ledger. Traditional methods like Proof of Work and Proof of Stake can suffer from latency and scalability challenges, especially as networks grow.

Pack and Spread introduces a graph-theoretic approach to accelerate consensus. It selects a subset of nodes called a d-packing set; a group of nodes at least d + 1 hops apart. Consensus propagation is initiated from these well-distributed, high-degree nodes, which ensures that every other node is within d hops of a source.

This design reduces propagation delays, improves reliability, and strengthens decentralization, particularly in medium-to-large blockchain networks
. Experimental results show faster average propagation times, lower variability, and up to an 80% reduction in worst-case propagation delays

**Status**

This project is ongoing. We are actively developing and refining the Pack and Spread algorithm. At this stage, only the core code of the d-packing routine is provided to illustrate the computational idea (see the attached dPackIt.c). A full implementation integrated with blockchain simulators, along with extended benchmarks and optimizations, will be released as the work progresses.

**Thank you**
