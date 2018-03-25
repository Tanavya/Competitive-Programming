cmake_minimum_required(VERSION 3.8)
project(Competitive_Programming)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ComputationalGeometry/Implementation/PointsLinesAndStuff.cpp
        DataStructures/Implementation/BinaryIndexedTrees.cpp
        DataStructures/Implementation/DisjointSets.cpp
        DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp
        DataStructures/Implementation/MergeSortTree.cpp
        DataStructures/Implementation/PersistentSegmentTree.cpp
        DataStructures/Implementation/Pointers.cpp
        DataStructures/Implementation/SegmentTree_RMQ.cpp
        "DataStructures/(TODO)HackerEarth_LittleDeepuAndArray.cpp"
        "DataStructures/(TODO)OPC_FindThePermutation.cpp"
        "DataStructures/(TODO)SPOJ_DynamicGraphConnectivity.cpp"
        DataStructures/CC_BlockedWebsites.cpp
        DataStructures/CC_MultiplesOf3.cpp
        DataStructures/HackerEarth_CityAndCampers2.cpp
        DataStructures/HackerEarth_CityAndSoldiers.cpp
        DataStructures/HackerEarth_FightInNinjaWorld.cpp
        DataStructures/HackerEarth_HelpAshu.cpp
        DataStructures/HackerEarth_ModifiedLIS.cpp
        DataStructures/HackerEarth_MonkAndOtakuland.cpp
        DataStructures/HackerEarth_RoyAndCoinBoxes.cpp
        DataStructures/SPOJ_DQuery.cpp
        DataStructures/SPOJ_KQuery.cpp
        DataStructures/SPOJ_KQuery2.cpp
        DataStructures/SPOJ_KthNumber.cpp
        DataStructures/SPOJ_OrderStatisticSet.cpp
        DynamicProgramming/OnTrees/CF161D_DistanceTree.cpp
        DynamicProgramming/OnTrees/CF337D_BookOfEvil.cpp
        DynamicProgramming/OnTrees/CF440D_BerlandFederalization.cpp
        DynamicProgramming/OnTrees/CF462D_ApplemanAndTree.cpp
        DynamicProgramming/OnTrees/CF682C_AlyonaAndTheTree.cpp
        DynamicProgramming/OnTrees/CF758E_BrokenTree.cpp
        DynamicProgramming/OnTrees/CF771C_BearAndTreeJumps.cpp
        DynamicProgramming/OnTrees/CFDPOnTreesTutP3b.cpp
        DynamicProgramming/OnTrees/CFDPOnTreesTutP4.cpp
        DynamicProgramming/OnTrees/HackerEarth_CountingOnTree.cpp
        DynamicProgramming/OnTrees/IOI2005_Rivers.cpp
        DynamicProgramming/OnTrees/IOITC_CateringContracts.cpp
        DynamicProgramming/OnTrees/OPC_3WaySplit.cpp
        DynamicProgramming/OnTrees/OPC_CateringContracts.cpp
        DynamicProgramming/OnTrees/SubtreesWithKNodes.cpp
        DynamicProgramming/OnTrees/TIMUS_BinaryAppleTree.cpp
        DynamicProgramming/CC_SealingUp.cpp
        DynamicProgramming/CC_TiduAndFrustratedTeacher.cpp
        DynamicProgramming/CF347D_LuckyCommonSubsequence.cpp
        DynamicProgramming/CF347D_LuckyCommonSubsequence2.cpp
        DynamicProgramming/CF385C_BearAndPrimeNumbers.cpp
        DynamicProgramming/CF414B_MashmokhAndACM.cpp
        DynamicProgramming/CF416C_BookingSystem.cpp
        DynamicProgramming/CF430D_WorkingOut.cpp
        DynamicProgramming/CF474D_Flowers.cpp
        DynamicProgramming/CF478D_RedGreenTowers.cpp
        DynamicProgramming/CF4D_MysteriousPresent.cpp
        DynamicProgramming/CF507D_TheMathsLecture.cpp
        DynamicProgramming/CF544C_WritingCode.cpp
        DynamicProgramming/CF580D_KefaAndDishes.cpp
        DynamicProgramming/CF588D_DuffInBeach.cpp
        DynamicProgramming/CF61D_EternalVictory.cpp
        DynamicProgramming/CF628B_NewSkateboard.cpp
        DynamicProgramming/CF706C_HardProblem.cpp
        DynamicProgramming/CF711C_ColoringTrees.cpp
        DynamicProgramming/CF762D_MaximumPath.cpp
        DynamicProgramming/CF789C_FunctionsAgain.cpp
        DynamicProgramming/CF837D_RoundSubset.cpp
        DynamicProgramming/CoinChange.cpp
        DynamicProgramming/INOI_Brackets.cpp
        DynamicProgramming/INOI_CalvinsGame.cpp
        DynamicProgramming/INOI_SpecialSums.cpp
        DynamicProgramming/OPC_LongestPalindrome.cpp
        DynamicProgramming/OPC_NumberOfTilings.cpp
        DynamicProgramming/SPOJ_ACMaker.cpp
        DynamicProgramming/SPOJ_Activities.cpp
        DynamicProgramming/SPOJ_Aibohphobia.cpp
        DynamicProgramming/SPOJ_Alphacode.cpp
        DynamicProgramming/SPOJ_BuyingApples.cpp
        DynamicProgramming/USACO2017P2.cpp
        DynamicProgramming/UVa10306_eCoins.cpp
        DynamicProgramming/UVa10337_FlightPlanner.cpp
        DynamicProgramming/UVa10496_CollectingBeepers.cpp
        DynamicProgramming/UVa10616_DivisibleGroupSums.cpp
        DynamicProgramming/UVa10721_BarCodes.cpp
        DynamicProgramming/UVa10819_TroubleOf13Dots.cpp
        DynamicProgramming/UVa11284_ShoppingTrip.cpp
        DynamicProgramming/UVa11517_ExactChange.cpp
        DynamicProgramming/UVa11566_LetsYumCha.cpp
        DynamicProgramming/UVa216_GettingInLine.cpp
        DynamicProgramming/UVa357_LetMeCountTheWays.cpp
        DynamicProgramming/ZCO_Rectangle.cpp
        GraphTheory/Implementation/Algorithm_BellmanFord.cpp
        GraphTheory/Implementation/Algorithm_Dijkstra.cpp
        GraphTheory/Implementation/Algorithm_FloydWarshall.cpp
        GraphTheory/Implementation/Algorithm_Kruskals.cpp
        GraphTheory/Implementation/ArticulationPointsAndBridges.cpp
        "GraphTheory/Implementation/LowestCommonAncestor(BinaryLifting).cpp"
        GraphTheory/Implementation/LowestCommonAncestor.cpp
        GraphTheory/Implementation/SCCTarjan.cpp
        GraphTheory/Implementation/TopologicalSort.cpp
        GraphTheory/APIO2009_ATMRobbery.cpp
        GraphTheory/CC_KingdomUnity.cpp
        GraphTheory/CF764C_TimofeyAndTree.cpp
        GraphTheory/IOI2009_Mecho.cpp
        GraphTheory/OPC_HighSpeedNetwork.cpp
        GraphTheory/SPOJ_LCA.cpp
        ICOPracticeProblems/AbsolutelyIncreasingSubsequence/AbsolutelyIncreasingSubsequence.cpp
        ICOPracticeProblems/AStandardTreeProblem/AStandardTreeProblem.cpp
        ICOPracticeProblems/Codeatsi/Codeatsi.cpp
        ICOPracticeProblems/NinjaCake/NinjaCake.cpp
        ICOPracticeProblems/PyramidFalls/PyramidFalls.cpp
        ICOPracticeProblems/YetAnotherGeometryProblem/YetAnotherGeometryProblem.cpp
        ICOPracticeProblems/YetAnotherGeometryProblem.cpp
        OtherAlgorithms/GreatestCommonDivisor.cpp
        OtherAlgorithms/IntervalPartitioning.cpp
        OtherAlgorithms/IntervalScheduling.cpp
        OtherAlgorithms/KnapsackProblem.cpp
        OtherAlgorithms/LongestIncreasingSubsequence.cpp
        OtherAlgorithms/ManachersAlgo.cpp
        OtherAlgorithms/MatrixExponentiation-FibSequence.cpp
        OtherAlgorithms/MatrixExponentiation.cpp
        OtherAlgorithms/Max2DRangeSum.cpp
        OtherAlgorithms/TernarySearch.cpp
        SyntaxProgrammingProblems/CheapTravel.cpp
        SyntaxProgrammingProblems/FancyFence.cpp
        SyntaxProgrammingProblems/GoodSequences.cpp
        SyntaxProgrammingProblems/GraphReversal.cpp
        SyntaxProgrammingProblems/HelpTheSplitCorgis.cpp
        SyntaxProgrammingProblems/HowManyRoutes.cpp
        SyntaxProgrammingProblems/MinimumPossibleTraverse.cpp
        SyntaxProgrammingProblems/ModifiedLCS.cpp
        SyntaxProgrammingProblems/SolveTheGivenEquation.cpp
        Miscellaneous/BitMasking.cpp
        Miscellaneous/BlownGarland.cpp
        "Miscellaneous/CC_ CHEFPCHF.cpp"
        Miscellaneous/CC_Calculator.cpp
        Miscellaneous/CC_CAPTCITI.cpp
        Miscellaneous/CC_ChefandCycledCycles.cpp
        Miscellaneous/CC_ChefAndDice.cpp
        Miscellaneous/CC_ChefAndFeast.cpp
        Miscellaneous/CC_ChefAndFibonacciArray.cpp
        Miscellaneous/CC_ChefAndMagicArrays.cpp
        Miscellaneous/CC_ChefAndPrimeQueries.cpp
        Miscellaneous/CC_ChefAndSubarray.cpp
        Miscellaneous/CC_ChefAndSubsequences.cpp
        Miscellaneous/CC_ChefAndTraingles.cpp
        Miscellaneous/CC_ChefAndVolunteerService.cpp
        Miscellaneous/CC_CHEFSIGN.cpp
        Miscellaneous/CC_CleaningTheSpace.cpp
        Miscellaneous/CC_ConnectingComputers.cpp
        Miscellaneous/CC_ConsecutiveSnakes.cpp
        Miscellaneous/CC_FillTheMatrix.cpp
        Miscellaneous/CC_Impersonating.cpp
        Miscellaneous/CC_IPCTrainers.cpp
        Miscellaneous/CC_JosephLand.cpp
        Miscellaneous/CC_PairWiseUnionOfSet.cpp
        Miscellaneous/CC_PyramidFalls.cpp
        Miscellaneous/CC_RobotsInADAG.cpp
        Miscellaneous/CC_SerejaAndCommands.cpp
        Miscellaneous/CC_ShootingOnTheArray.cpp
        Miscellaneous/CC_SnakesAndDiscussion.cpp
        Miscellaneous/CC_SnakesAndGraph.cpp
        Miscellaneous/CC_SNCOUP.cpp
        Miscellaneous/CC_SumOfCubes.cpp
        Miscellaneous/CC_TiduAndRatings.cpp
        Miscellaneous/CC_TravelingMinister.cpp
        Miscellaneous/CC_Triplets.cpp
        Miscellaneous/CC_WeaselDoesXOROnTree.cpp
        Miscellaneous/CC_WeaselFindsStaircase.cpp
        Miscellaneous/CC_WeirdBacteria.cpp
        Miscellaneous/CCC_GreedyForPies.cpp
        Miscellaneous/CF27E_SmallestNumberWithGivenDivisors.cpp
        Miscellaneous/CF747C_Servers.cpp
        Miscellaneous/CF747D_WinterIsComing.cpp
        Miscellaneous/COREPrelims_AuntyPrime.cpp
        Miscellaneous/FightingZombies.cpp
        Miscellaneous/HolidayOfEquity.cpp
        Miscellaneous/INOI2017P2.cpp
        Miscellaneous/INOI_BinaryStrings.cpp
        Miscellaneous/INOI_HighwayBypass.cpp
        Miscellaneous/INOI_SequenceLand.cpp
        Miscellaneous/INOI_TableSum.cpp
        Miscellaneous/INOI_Triathlon.cpp
        Miscellaneous/INOI_WealthDisparity.cpp
        Miscellaneous/IOITC_BabaAndBitmasks.cpp
        Miscellaneous/kthDivisor.cpp
        Miscellaneous/LazyLoading.cpp
        Miscellaneous/ManicMoving.cpp
        Miscellaneous/MaxPath.cpp
        myheader.h
        Miscellaneous/OPC_EqualGifts.cpp
        Miscellaneous/OPC_IndPyramid.cpp
        Miscellaneous/OPC_LeadGame.cpp
        Miscellaneous/OPC_MinimumTurnRoute.cpp
        Miscellaneous/OPC_RailwayCateringContacts.cpp
        Miscellaneous/OPC_SiruseriMetro.cpp
        Miscellaneous/Parquet.cpp
        Miscellaneous/PROC17_Traffic.cpp
        Miscellaneous/ProgressPie.cpp
        Miscellaneous/race.cpp
        Miscellaneous/RustAndMurderer.cpp
        Miscellaneous/SIS.cpp
        Miscellaneous/SPOJ_DNASequences.cpp
        Miscellaneous/SPOJ_DNASequencesCopy.cpp
        Miscellaneous/SPOJ_SubArrays.cpp
        Miscellaneous/SynchronousShopping.cpp
        Miscellaneous/TwoStrings.cpp
        Miscellaneous/untitled.cpp
        Miscellaneous/USBvsPS2.cpp
        Miscellaneous/UVa10684_Jackpot.cpp
        Miscellaneous/UVa10755_GarbageHeap.cpp
        Miscellaneous/UVa11456_Trainsorting.cpp
        Miscellaneous/UVa1177_AGeneralRecurrenceRelation.cpp
        Miscellaneous/UVa12405_Scarecrow.cpp
        Miscellaneous/UVa787_MaxSubSequenceProduct.cpp
        Miscellaneous/UVa927.cpp
        Miscellaneous/UVa_8Queens.cpp
        Miscellaneous/UVa_AnotherNQueenProblem.cpp
        Miscellaneous/UVa_BackToThe8Queens.cpp
        Miscellaneous/UVa_Bars.cpp
        Miscellaneous/UVa_BusDriverProblem.cpp
        Miscellaneous/UVa_CD.cpp
        Miscellaneous/UVa_CitizenAttentionOffices.cpp
        Miscellaneous/UVa_ClosestSums.cpp
        Miscellaneous/UVa_CoinCollector.cpp
        Miscellaneous/UVa_DartAMania.cpp
        Miscellaneous/UVa_ExactSum.cpp
        Miscellaneous/UVa_ExpertEnough.cpp
        Miscellaneous/UVa_FillTheContainers.cpp
        Miscellaneous/UVa_FractionsAgain.cpp
        Miscellaneous/UVa_Grapevine.cpp
        Miscellaneous/UVa_GraphColoring.cpp
        Miscellaneous/UVa_GraphColoring2.cpp
        Miscellaneous/UVa_GridGame.cpp
        Miscellaneous/UVa_GroceryStore.cpp
        Miscellaneous/UVa_HelpingFillBates.cpp
        Miscellaneous/UVa_LEDTest.cpp
        Miscellaneous/UVa_Lotto.cpp
        Miscellaneous/UVa_MonkeyAndOiledBamboo.cpp
        Miscellaneous/UVa_Password.cpp
        Miscellaneous/UVa_PathInColouredField.cpp
        Miscellaneous/UVa_PrimeRingProblem.cpp
        Miscellaneous/UVa_RatAttack.cpp
        Miscellaneous/UVa_Sales.cpp
        Miscellaneous/UVa_SolveIt.cpp
        Miscellaneous/UVa_SumItUp.cpp
        Miscellaneous/UVa_TourDeFrance.cpp
        Miscellaneous/UVa_Y2KAccountingBug.cpp
        Miscellaneous/UVa_Zones.cpp
        OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp Miscellaneous/CC_ChefGoesLeftRight.cpp DataStructures/CC_ChefAndSubarrayQueries.cpp DataStructures/CC_ChefAndSubarrayQueries2.cpp DataStructures/SPOJ_GSS1.cpp GraphTheory/Implementation/DFSConnectedComponents.cpp Miscellaneous/CC_ProductOnSegment.cpp DataStructures/SPOJ_QTREE1.cpp DataStructures/CC_LoversGift.cpp DynamicProgramming/CF495D_ObsessiveString.cpp DynamicProgramming/CF383D_Antimatter.cpp Miscellaneous/CF525E_AnyaAndCubes.cpp OtherAlgorithms/Bitmasks.cpp Miscellaneous/CF688E_TheValuesYouCanMake.cpp GraphTheory/CF659E_NewReform.cpp DataStructures/CC_LoversGift2.cpp.cpp DynamicProgramming/CF479D_RidingInALift.cpp Miscellaneous/CF340D_BubbleSortGraph.cpp DataStructures/CC_ChefAndMediumProblem2.cpp DynamicProgramming/ExunPrelimsP2.cpp GraphTheory/CF892E_Envy.cpp DataStructures/CF686D_KayAndSnowflake.cpp Miscellaneous/CF519E_AAndBLectureRooms.cpp DynamicProgramming/Exun2017_Digex.cpp DynamicProgramming/Exun2017_DigexReturns.cpp DynamicProgramming/IOI96_AGame.cpp DynamicProgramming/IOI2000_PostOffices.cpp DataStructures/CF342E_XeniaAndTree.cpp ComputationalGeometry/Implementation/GeometryStuff.cpp OtherAlgorithms/Sieve.cpp OtherAlgorithms/ModularInverse.cpp OtherAlgorithms/MosAlgorithm.cpp DataStructures/Implementation/Tries.cpp DataStructures/HackerEarth_Trie.cpp DataStructures/LiveArchive_XorSum.cpp DataStructures/CF617E_XORAndFavouriteNumber.cpp DataStructures/CF589G_Hiring.cpp DataStructures/Implementation/SqrtDecomposition_IntervalSum.cpp OtherAlgorithms/SPOJ_DynamicGraphConnectivity2.cpp GraphTheory/SPOJ_DynamicGraphConnectivity2.cpp GraphTheory/CF257B_JzzhuAndCities.cpp Misc.cpp DataStructures/CF899F_LettersRemoving.cpp DataStructures/SPOJ_KthNumber_Persistence.cpp DataStructures/CF899E_SegmentsRemoval.cpp Miscellaneous/IARCS_PayingThePrice.cpp GraphTheory/USACO_Relocation.cpp Miscellaneous/USACO_CowIDs.cpp DynamicProgramming/USACO_BalancedCowBreeds.cpp DynamicProgramming/CC_TooMuchSweetness.cpp DynamicProgramming/GCJ_LastHit.cpp GraphTheory/CF115A_Party.cpp Miscellaneous/IARCS_RankFraud.cpp DynamicProgramming/SPOJ_TheCourier.cpp Miscellaneous/AIO_CoreysParty.cpp DynamicProgramming/GFG_ShortestCommonSupersequence.cpp DynamicProgramming/SPOJ_KRECT.cpp DynamicProgramming/CF864E_Fire.cpp DynamicProgramming/HackerRank_Troyangles.cpp GraphTheory/SPOJ_OTOCI.cpp DynamicProgramming/CC_PartitionCount.cpp GraphTheory/CF716D_CompleteTheGraph.cpp GraphTheory/CSA_TriangularMatrix.cpp DynamicProgramming/CF407B_LongPath.cpp DynamicProgramming/CF118D_CaesarsLegions.cpp GraphTheory/UVa10342_AlwaysLate.cpp GraphTheory/CF567E_PresidentAndRoads.cpp DataStructures/CC_PishtyAndTree.cpp DataStructures/SPOJ_GSS2.cpp DataStructures/SPOJ_KQueryo.cpp DataStructures/Implementation/RangeQueryAndUpdates_PrefixTrick.cpp DataStructures/SPOJ_GSS3.cpp DataStructures/SPOJ_GSS4.cpp DataStructures/SPOJ_GSS5.cpp DataStructures/CC_GiveAway.cpp DataStructures/Implementation/PersistentSegmentTreeWithoutPointers.cpp DataStructures/KQuery2_alternate.cpp DataStructures/CC_Sorting.cpp DataStructures/SPOJ_DQuery_MosAlgo.cpp DataStructures/SPOJ_DQuery_Persistence.cpp DataStructures/CC_XorQueries.cpp DataStructures/CC_SubInversing.cpp DataStructures/CC_CloneMe.cpp DataStructures/SPOJ_RPAR.cpp DataStructures/CF145E_LuckyQueries.cpp DataStructures/CF446C_DZYLovesFibonacciNumbers.cpp DataStructures/SPOJ_SEGSQRSS.cpp DataStructures/SPOJ_COT.cpp DataStructures/SPOJ_COT2.cpp GraphTheory/CC_VasyaAndLittleBear.cpp DynamicProgramming/OnTrees/CF915F_ImbalanceValueOfTree.cpp DataStructures/CC_ChefAndQueries.cpp DataStructures/CF226E_NobleKnightsPath.cpp Miscellaneous/CF220B_LittleElephantAndArray.cpp GraphTheory/CF919D_Substring.cpp Miscellaneous/CC_ChefAndXorQueries.cpp Miscellaneous/CF13E_Holes.cpp DataStructures/CF86D_PowerfulArray.cpp DataStructures/CC_ChefAndGraphQueries.cpp Miscellaneous/CC_BrokenClock.cpp DataStructures/CC_ChefAndOddQueries.cpp DataStructures/CC_StrangeQueries.cpp DataStructures/Implementation/Treap.cpp DataStructures/SPOJ_OrderStatisticSet_Treap.cpp DataStructures/SPOJ_GSS6.cpp DataStructures/Implementation/ImplicitTreap.cpp DataStructures/CF375D_TreeAndQueries.cpp DataStructures/CF506_MrKutayutasColorfulGraph.cpp DataStructures/CF348C_SubsetSums.cpp DataStructures/CF398D_InstantMessenger.cpp DataStructures/Exun2017_ArrayStudy.cpp GraphTheory/CC_TALCA.cpp DynamicProgramming/OnTrees/CF816C_KarenAndSupermarket.cpp GraphTheory/CF932D_Tree.cpp GraphTheory/IOITC_GraphLIS.cpp DynamicProgramming/CF81E_Pairs.cpp GraphTheory/SPOJ_AMR10J.cpp DynamicProgramming/OnTrees/SPOJ_TwoPaths.cpp DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp GraphTheory/CF505D_KitayutasTechnology.cpp GraphTheory/Implementation/DetectingCyclesDirectedGraph.cpp DataStructures/Implementation/HeavyLightDecomposition.cpp DataStructures/SPOJ_COT2_HLD.cpp DataStructures/SPOJ_QTREE4.cpp DataStructures/SPOJ_COT2_ALT.cpp DataStructures/SPOJ_QTREE5.cpp DataStructures/CF342E_XeniaAndTree_Centroid.cpp DataStructures/IOI2011_Race.cpp OtherAlgorithms/FastIO.cpp DataStructures/SPOJ_ACQUIRE.cpp DataStructures/Implementation/LiChaoSegmentTree.cpp DataStructures/Implementation/ConvexHullTrick.cpp DataStructures/CC_CyclistRace.cpp DynamicProgramming/UVa10304_OptimalBST.cpp DynamicProgramming/SPOJ_ACQUIRE_1D1D.cpp DynamicProgramming/HR_GuardiansOfTheLunatics.cpp DynamicProgramming/CF319C_KalilaAndDimna.cpp DynamicProgramming/SPOJ_NKLeaves.cpp DynamicProgramming/CF311B_CatsTransport.cpp DynamicProgramming/CF321E_CielAndGondolas.cpp DynamicProgramming/SPOJ_BRKSTRING.cpp DynamicProgramming/HR_AlienLanguages.cpp DataStructures/CF600E_LomsatGelral.cpp GraphTheory/CF950E_DataCenterMaintenance.cpp OtherAlgorithms/SlopeTrick.cpp DynamicProgramming/CF626F_GroupProjects.cpp DynamicProgramming/CF466D_IncreaseSequence.cpp GraphTheory/IOITC2014_Compilation.cpp DynamicProgramming/IOITC2014_DemolitionMan.cpp DynamicProgramming/IOITC2015_SherlockAndWatson.cpp GraphTheory/IOITC2015_Hospital.cpp DynamicProgramming/IOITC2014_SwordsOfGilgamesh.cpp DataStructures/Implementation/SegmentTreeBeats.cpp DataStructures/CF438D_TheChildAndSequence.cpp DataStructures/IOITC2015_ChandraguptaBST.cpp DataStructures/IOITC2015_ChandraguptaAndTransport.cpp DataStructures/IOITC2015_ChandraguptaInsurgents.cpp Miscellaneous/IOITC2015_DArray.cpp)

add_executable(Competitive_Programming ${SOURCE_FILES})
add_executable(CF347D_LuckyCommonSubsequence2 DynamicProgramming/CF347D_LuckyCommonSubsequence2.cpp)
add_executable(Knuth-Morris-Pratt-Algorithm OtherAlgorithms/Knuth-Morris-Pratt-Algorithm.cpp)
add_executable(ManachersAlgo OtherAlgorithms/ManachersAlgo.cpp)
add_executable(CC_ChefGoesLeftRight Miscellaneous/CC_ChefGoesLeftRight.cpp)
add_executable(CC_ChefAndSubarrayQueries DataStructures/CC_ChefAndSubarrayQueries.cpp)
add_executable(CC_ChefAndSubarrayQueries2 DataStructures/CC_ChefAndSubarrayQueries2.cpp)
add_executable(SPOJ_GSS1 DataStructures/SPOJ_GSS1.cpp)
add_executable(DFSConnectedComponents GraphTheory/Implementation/DFSConnectedComponents.cpp)
add_executable(CC_ProductOnSegment Miscellaneous/CC_ProductOnSegment.cpp)
add_executable(SPOJ_QTREE1 DataStructures/SPOJ_QTREE1.cpp)
add_executable(CC_LoversGift DataStructures/CC_LoversGift.cpp)
add_executable(CF495D_ObsessiveString DynamicProgramming/CF495D_ObsessiveString.cpp)
add_executable(CF383D_Antimatter DynamicProgramming/CF383D_Antimatter.cpp)
add_executable(CF525E_AnyaAndCubes Miscellaneous/CF525E_AnyaAndCubes.cpp)
add_executable(CF688E_TheValuesYouCanMake Miscellaneous/CF688E_TheValuesYouCanMake.cpp)
add_executable(CF659E_NewReform GraphTheory/CF659E_NewReform.cpp)
add_executable(CF479D_RidingInALift DynamicProgramming/CF479D_RidingInALift.cpp)
add_executable(CF340D_BubbleSortGraph Miscellaneous/CF340D_BubbleSortGraph.cpp)
add_executable(CC_ChefAndMediumProblem2 DataStructures/CC_ChefAndMediumProblem2.cpp)
add_executable(ExunPrelimsP2 DynamicProgramming/ExunPrelimsP2.cpp)
add_executable(CF892E_Envy GraphTheory/CF892E_Envy.cpp)
add_executable(CF686D_KayAndSnowflake DataStructures/CF686D_KayAndSnowflake.cpp)
add_executable(CF519E_AAndBLectureRooms Miscellaneous/CF519E_AAndBLectureRooms.cpp)
add_executable(Exun2017_Digex DynamicProgramming/Exun2017_Digex.cpp)
add_executable(Exun2017_DigexReturns DynamicProgramming/Exun2017_DigexReturns.cpp)
add_executable(IOI96_AGame DynamicProgramming/IOI96_AGame.cpp)
add_executable(IOI2000_PostOffices DynamicProgramming/IOI2000_PostOffices.cpp)
add_executable(CF342E_XeniaAndTree DataStructures/CF342E_XeniaAndTree.cpp)
add_executable(PointsLinesAndStuff ComputationalGeometry/Implementation/PointsLinesAndStuff.cpp)
add_executable(ModularInverse OtherAlgorithms/ModularInverse.cpp)
add_executable(SCCTarjan GraphTheory/Implementation/SCCTarjan.cpp)
add_executable(LazyPropSegmentTree_IntervalSum DataStructures/Implementation/LazyPropSegmentTree_IntervalSum.cpp)
add_executable(MosAlgorithm OtherAlgorithms/MosAlgorithm.cpp)
add_executable(Tries DataStructures/Implementation/Tries.cpp)
add_executable(HackerEarth_Trie DataStructures/HackerEarth_Trie.cpp)
add_executable(LiveArchive_XorSum DataStructures/LiveArchive_XorSum.cpp)
add_executable(CF617E_XORAndFavouriteNumber DataStructures/CF617E_XORAndFavouriteNumber.cpp)
add_executable(CF589G_Hiring DataStructures/CF589G_Hiring.cpp)
add_executable(SqrtDecomposition_IntervalSum DataStructures/Implementation/SqrtDecomposition_IntervalSum.cpp)
add_executable(SPOJ_DynamicGraphConnectivity2 OtherAlgorithms/SPOJ_DynamicGraphConnectivity2.cpp)
add_executable(CF257B_JzzhuAndCities GraphTheory/CF257B_JzzhuAndCities.cpp)
add_executable(Misc Misc.cpp)
add_executable(CF899F_LettersRemoving DataStructures/CF899F_LettersRemoving.cpp)
add_executable(SPOJ_KthNumber_Persistence DataStructures/SPOJ_KthNumber_Persistence.cpp)
add_executable(IARCS_PayingThePrice Miscellaneous/IARCS_PayingThePrice.cpp)
add_executable(USACO_Relocation GraphTheory/USACO_Relocation.cpp)
add_executable(USACO_CowIDs Miscellaneous/USACO_CowIDs.cpp)
add_executable(USACO_BalancedCowBreeds DynamicProgramming/USACO_BalancedCowBreeds.cpp)
add_executable(CC_TooMuchSweetness DynamicProgramming/CC_TooMuchSweetness.cpp)
add_executable(GCJ_LastHit DynamicProgramming/GCJ_LastHit.cpp)
add_executable(CF115A_Party GraphTheory/CF115A_Party.cpp)
add_executable(IARCS_RankFraud Miscellaneous/IARCS_RankFraud.cpp)
add_executable(SPOJ_TheCourier DynamicProgramming/SPOJ_TheCourier.cpp)
add_executable(AIO_CoreysParty Miscellaneous/AIO_CoreysParty.cpp)
add_executable(GFG_ShortestCommonSupersequence DynamicProgramming/GFG_ShortestCommonSupersequence.cpp)
add_executable(SPOJ_KRECT DynamicProgramming/SPOJ_KRECT.cpp)
add_executable(CF864E_Fire DynamicProgramming/CF864E_Fire.cpp)
add_executable(CC_PartitionCount DynamicProgramming/CC_PartitionCount.cpp)
add_executable(SPOJ_OTOCI GraphTheory/SPOJ_OTOCI.cpp)
add_executable(CF716D_CompleteTheGraph GraphTheory/CF716D_CompleteTheGraph.cpp)
add_executable(CSA_TriangularMatrix GraphTheory/CSA_TriangularMatrix.cpp)
add_executable(CF407B_LongPath DynamicProgramming/CF407B_LongPath.cpp)
add_executable(CF118D_CaesarsLegions DynamicProgramming/CF118D_CaesarsLegions.cpp)
add_executable(UVa10342_AlwaysLate GraphTheory/UVa10342_AlwaysLate.cpp)
add_executable(CF567E_PresidentAndRoads GraphTheory/CF567E_PresidentAndRoads.cpp)
add_executable(CC_PishtyAndTree DataStructures/CC_PishtyAndTree.cpp)
add_executable(CC_PishtyAndTree_Alternate DataStructures/CC_PishtyAndTree_Alternate.cpp)
add_executable(SPOJ_KQuery DataStructures/SPOJ_KQuery.cpp)
add_executable(SPOJ_KQueryo DataStructures/SPOJ_KQueryo.cpp)
add_executable(RangeQueryAndUpdates_PrefixTrick DataStructures/Implementation/RangeQueryAndUpdates_PrefixTrick.cpp)
add_executable(SPOJ_GSS2 DataStructures/SPOJ_GSS2.cpp)
add_executable(SPOJ_GSS3 DataStructures/SPOJ_GSS3.cpp)
add_executable(SPOJ_GSS4 DataStructures/SPOJ_GSS4.cpp)
add_executable(SPOJ_GSS5 DataStructures/SPOJ_GSS5.cpp)
add_executable(CC_GiveAway DataStructures/CC_GiveAway.cpp)
add_executable(SPOJ_KQuery2 DataStructures/SPOJ_KQuery2.cpp)
add_executable(KQuery2_alternate DataStructures/KQuery2_alternate.cpp)
add_executable(CC_Sorting DataStructures/CC_Sorting.cpp)
add_executable(SPOJ_DQuery_MosAlgo DataStructures/SPOJ_DQuery_MosAlgo.cpp)
add_executable(SPOJ_DQuery_Persistence DataStructures/SPOJ_DQuery_Persistence.cpp)
add_executable(CC_XorQueries DataStructures/CC_XorQueries.cpp)
add_executable(CC_SubInversing DataStructures/CC_SubInversing.cpp)
add_executable(CC_CloneMe DataStructures/CC_CloneMe.cpp)
add_executable(SPOJ_RPAR DataStructures/SPOJ_RPAR.cpp)
add_executable(CF145E_LuckyQueries DataStructures/CF145E_LuckyQueries.cpp)
add_executable(CF446C_DZYLovesFibonacciNumbers DataStructures/CF446C_DZYLovesFibonacciNumbers.cpp)
add_executable(SPOJ_SEGSQRSS DataStructures/SPOJ_SEGSQRSS.cpp)
add_executable(SPOJ_COT DataStructures/SPOJ_COT.cpp)
add_executable(SPOJ_COT2 DataStructures/SPOJ_COT2.cpp)
add_executable(CC_VasyaAndLittleBear GraphTheory/CC_VasyaAndLittleBear.cpp)
add_executable(CF915F_ImbalanceValueOfTree DynamicProgramming/OnTrees/CF915F_ImbalanceValueOfTree.cpp)
add_executable(CC_ChefAndQueries DataStructures/CC_ChefAndQueries.cpp)
add_executable(CF220B_LittleElephantAndArray Miscellaneous/CF220B_LittleElephantAndArray.cpp)
add_executable(CC_ChefAndXorQueries Miscellaneous/CC_ChefAndXorQueries.cpp)
add_executable(CF13E_Holes Miscellaneous/CF13E_Holes.cpp)
add_executable(CF86D_PowerfulArray DataStructures/CF86D_PowerfulArray.cpp)
add_executable(CC_ChefAndGraphQueries DataStructures/CC_ChefAndGraphQueries.cpp)
add_executable(CC_BrokenClock Miscellaneous/CC_BrokenClock.cpp)
add_executable(CC_ChefAndOddQueries DataStructures/CC_ChefAndOddQueries.cpp)
add_executable(CC_StrangeQueries DataStructures/CC_StrangeQueries.cpp)
add_executable(Treap DataStructures/Implementation/Treap.cpp)
add_executable(SPOJ_OrderStatisticSet_Treap DataStructures/SPOJ_OrderStatisticSet_Treap.cpp)
add_executable(ImplicitTreap DataStructures/Implementation/ImplicitTreap.cpp)
add_executable(SPOJ_GSS6 DataStructures/SPOJ_GSS6.cpp)
add_executable(CF375D_TreeAndQueries DataStructures/CF375D_TreeAndQueries.cpp)
add_executable(CF506_MrKutayutasColorfulGraph DataStructures/CF506_MrKutayutasColorfulGraph.cpp)
add_executable(CF348C_SubsetSums DataStructures/CF348C_SubsetSums.cpp)
add_executable(CF398D_InstantMessenger DataStructures/CF398D_InstantMessenger.cpp)
add_executable(Exun2017_ArrayStudy DataStructures/Exun2017_ArrayStudy.cpp)
add_executable(CC_TALCA GraphTheory/CC_TALCA.cpp)
add_executable(TIMUS_BinaryAppleTree DynamicProgramming/OnTrees/TIMUS_BinaryAppleTree.cpp)
add_executable(CF816C_KarenAndSupermarket DynamicProgramming/OnTrees/CF816C_KarenAndSupermarket.cpp)
add_executable(CF932D_Tree GraphTheory/CF932D_Tree.cpp)
add_executable(IOITC_GraphLIS GraphTheory/IOITC_GraphLIS.cpp)
add_executable(CF81E_Pairs DynamicProgramming/CF81E_Pairs.cpp)
add_executable(SPOJ_AMR10J GraphTheory/SPOJ_AMR10J.cpp)
add_executable(SPOJ_TwoPaths DynamicProgramming/OnTrees/SPOJ_TwoPaths.cpp)
add_executable(CF868E_PolicemanAndTree DynamicProgramming/OnTrees/CF868E_PolicemanAndTree.cpp)
add_executable(CF505D_KitayutasTechnology GraphTheory/CF505D_KitayutasTechnology.cpp)
add_executable(HeavyLightDecomposition DataStructures/Implementation/HeavyLightDecomposition.cpp)
add_executable(SPOJ_QTREE5 DataStructures/SPOJ_QTREE5.cpp)
add_executable(CF342E_XeniaAndTree_Centroid DataStructures/CF342E_XeniaAndTree_Centroid.cpp)
add_executable(IOI2011_Race DataStructures/IOI2011_Race.cpp)
add_executable(SPOJ_QTREE4 DataStructures/SPOJ_QTREE4.cpp)
add_executable(SPOJ_ACQUIRE DataStructures/SPOJ_ACQUIRE.cpp)
add_executable(LiChaoSegmentTree DataStructures/Implementation/LiChaoSegmentTree.cpp)
add_executable(CC_CyclistRace DataStructures/CC_CyclistRace.cpp)
add_executable(KnuthOptimisation DynamicProgramming/OptimisationsAndTechniques/KnuthOptimisation.cpp)
add_executable(1D1DOptimisation DynamicProgramming/OptimisationsAndTechniques/1D1DOptimisation.cpp)
add_executable(SPOJ_ACQUIRE_1D1D DynamicProgramming/SPOJ_ACQUIRE_1D1D.cpp)
add_executable(DivideAndConquerOptimisation DynamicProgramming/OptimisationsAndTechniques/DivideAndConquerOptimisation.cpp)
add_executable(HR_GuardiansOfTheLunatics DynamicProgramming/HR_GuardiansOfTheLunatics.cpp)
add_executable(ConvexHullTrick DynamicProgramming/OptimisationsAndTechniques/ConvexHullTrick.cpp)
add_executable(CF319C_KalilaAndDimna DynamicProgramming/CF319C_KalilaAndDimna.cpp)
add_executable(SPOJ_NKLeaves DynamicProgramming/SPOJ_NKLeaves.cpp)
add_executable(CF311B_CatsTransport DynamicProgramming/CF311B_CatsTransport.cpp)
add_executable(CF321E_CielAndGondolas DynamicProgramming/CF321E_CielAndGondolas.cpp)
add_executable(ConvexHullTrick2 DynamicProgramming/OptimisationsAndTechniques/ConvexHullTrick2.cpp)
add_executable(SPOJ_BRKSTRING DynamicProgramming/SPOJ_BRKSTRING.cpp)
add_executable(HR_AlienLanguages DynamicProgramming/HR_AlienLanguages.cpp)
add_executable(CF600E_LomsatGelral DataStructures/CF600E_LomsatGelral.cpp)
add_executable(CF950E_DataCenterMaintenance GraphTheory/CF950E_DataCenterMaintenance.cpp)
add_executable(CF626F_GroupProjects DynamicProgramming/CF626F_GroupProjects.cpp)

add_executable(CF466D_IncreaseSequence DynamicProgramming/CF466D_IncreaseSequence.cpp)
add_executable(IOITC2014_Compilation GraphTheory/IOITC2014_Compilation.cpp)
add_executable(Bitmasks OtherAlgorithms/Bitmasks.cpp)
add_executable(IOITC2014_DemolitionMan DynamicProgramming/IOITC2014_DemolitionMan.cpp)
add_executable(IOITC2015_SherlockAndWatson DynamicProgramming/IOITC2015_SherlockAndWatson.cpp)
add_executable(IOITC2015_Hospital GraphTheory/IOITC2015_Hospital.cpp)
add_executable(IOITC2014_SwordsOfGilgamesh DynamicProgramming/IOITC2014_SwordsOfGilgamesh.cpp)
add_executable(SegmentTreeBeats DataStructures/Implementation/SegmentTreeBeats.cpp)
add_executable(CF438D_TheChildAndSequence DataStructures/CF438D_TheChildAndSequence.cpp)
add_executable(IOITC2015_ChandraguptaBST DataStructures/IOITC2015_ChandraguptaBST.cpp)
add_executable(IOITC2015_ChandraguptaAndTransport DataStructures/IOITC2015_ChandraguptaAndTransport.cpp)
add_executable(IOITC2015_ChandraguptaInsurgents DataStructures/IOITC2015_ChandraguptaInsurgents.cpp)