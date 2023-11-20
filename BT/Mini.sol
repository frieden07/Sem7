pragma solidity ^0.8.0;

contract VotingSystem {
    address public owner;
    string public electionName;
    mapping(bytes32 => uint256) public votes;
    bytes32[] public candidateList;
    bool public isVotingOpen;

    event VoteCast(address indexed voter, bytes32 candidate);

    constructor(string memory _electionName, bytes32[] memory _candidateList) {
        owner = msg.sender;
        electionName = _electionName;
        candidateList = _candidateList;
        isVotingOpen = true;
    }

    modifier onlyOwner() {
        require(msg.sender == owner, "Only the owner can perform this action");
        _;
    }

    modifier onlyDuringVoting() {
        require(isVotingOpen, "Voting is closed");
        _;
    }

    function closeVoting() public onlyOwner {
        isVotingOpen = false;
    }

    function vote(bytes32 _candidate) public onlyDuringVoting {
        require(isValidCandidate(_candidate), "Invalid candidate");
        votes[_candidate]++;
        emit VoteCast(msg.sender, _candidate);
    }

    function isValidCandidate(bytes32 _candidate) public view returns (bool) {
        for (uint i = 0; i < candidateList.length; i++) {
            if (candidateList[i] == _candidate) {
                return true;
            }
        }
        return false;
    }

    function getVotesForCandidate(bytes32 _candidate) public view returns (uint256) {
        require(isValidCandidate(_candidate), "Invalid candidate");
        return votes[_candidate];
    }

    function getCandidateList() public view returns (bytes32[] memory) {
        return candidateList;
    }
}


//["0x506f7370616c2031000000000000000000000000000000000000000000000000", "0x506f7370616c2032000000000000000000000000000000000000000000000000", "0x506f7370616c2033000000000000000000000000000000000000000000000000"]
