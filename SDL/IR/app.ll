; ModuleID = 'src/app.c'
source_filename = "src/app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noreturn nounwind uwtable
define dso_local void @app() local_unnamed_addr #0 {
  %1 = alloca [2 x [2244 x i32]], align 16
  call void @llvm.lifetime.start.p0(i64 17952, ptr nonnull %1) #4
  call void @llvm.memset.p0.i64(ptr noundef nonnull align 16 dereferenceable(17952) %1, i8 0, i64 17952, i1 false)
  br label %2

2:                                                ; preds = %6, %0
  %3 = phi i64 [ 1, %0 ], [ %7, %6 ]
  %4 = mul nuw nsw i64 %3, 264
  %5 = getelementptr inbounds nuw i8, ptr %1, i64 %4
  br label %9

6:                                                ; preds = %19
  %7 = add nuw nsw i64 %3, 1
  %8 = icmp eq i64 %7, 33
  br i1 %8, label %24, label %2, !llvm.loop !5

9:                                                ; preds = %19, %2
  %10 = phi i64 [ 1, %2 ], [ %22, %19 ]
  %11 = tail call i32 (...) @simRand() #4
  %12 = srem i32 %11, 10
  %13 = icmp eq i32 %12, 0
  br i1 %13, label %14, label %19

14:                                               ; preds = %9
  %15 = tail call i32 (...) @simRand() #4
  %16 = srem i32 %15, 50
  %17 = icmp eq i32 %16, 0
  %18 = select i1 %17, i32 16711680, i32 65280
  br label %19

19:                                               ; preds = %14, %9
  %20 = phi i32 [ %18, %14 ], [ 0, %9 ]
  %21 = getelementptr inbounds nuw i32, ptr %5, i64 %10
  store i32 %20, ptr %21, align 4, !tbaa !8
  %22 = add nuw nsw i64 %10, 1
  %23 = icmp eq i64 %22, 65
  br i1 %23, label %6, label %9, !llvm.loop !12

24:                                               ; preds = %6, %64
  %25 = phi i32 [ %66, %64 ], [ 0, %6 ]
  %26 = zext nneg i32 %25 to i64
  %27 = getelementptr inbounds nuw [2 x [2244 x i32]], ptr %1, i64 0, i64 %26
  br label %28

28:                                               ; preds = %36, %24
  %29 = phi i64 [ 0, %24 ], [ %30, %36 ]
  %30 = add nuw nsw i64 %29, 1
  %31 = getelementptr inbounds nuw i32, ptr %27, i64 %30
  %32 = trunc i64 %29 to i32
  %33 = shl i32 %32, 3
  br label %38

34:                                               ; preds = %49
  %35 = icmp eq i64 %40, 32
  br i1 %35, label %36, label %38, !llvm.loop !13

36:                                               ; preds = %34
  %37 = icmp eq i64 %30, 64
  br i1 %37, label %57, label %28, !llvm.loop !14

38:                                               ; preds = %34, %28
  %39 = phi i64 [ 0, %28 ], [ %40, %34 ]
  %40 = add nuw nsw i64 %39, 1
  %41 = mul nuw nsw i64 %40, 264
  %42 = getelementptr inbounds nuw i8, ptr %31, i64 %41
  %43 = load i32, ptr %42, align 4, !tbaa !8
  %44 = trunc i64 %39 to i32
  %45 = shl i32 %44, 3
  br label %46

46:                                               ; preds = %49, %38
  %47 = phi i32 [ 0, %38 ], [ %50, %49 ]
  %48 = add nuw nsw i32 %47, %33
  br label %52

49:                                               ; preds = %52
  %50 = add nuw nsw i32 %47, 1
  %51 = icmp eq i32 %50, 8
  br i1 %51, label %34, label %46, !llvm.loop !15

52:                                               ; preds = %52, %46
  %53 = phi i32 [ 0, %46 ], [ %55, %52 ]
  %54 = add nuw nsw i32 %53, %45
  tail call void @simPutPixel(i32 noundef %48, i32 noundef %54, i32 noundef %43) #4
  %55 = add nuw nsw i32 %53, 1
  %56 = icmp eq i32 %55, 8
  br i1 %56, label %49, label %52, !llvm.loop !16

57:                                               ; preds = %36
  tail call void (...) @simFlush() #4
  %58 = xor i32 %25, 1
  %59 = zext nneg i32 %58 to i64
  br label %60

60:                                               ; preds = %57, %70
  %61 = phi i64 [ 1, %57 ], [ %71, %70 ]
  %62 = mul nuw nsw i64 %61, 66
  %63 = trunc nuw nsw i64 %61 to i32
  br label %67

64:                                               ; preds = %70
  %65 = and i32 %25, 1
  %66 = xor i32 %65, 1
  br label %24, !llvm.loop !17

67:                                               ; preds = %60, %117
  %68 = phi i64 [ 1, %60 ], [ %120, %117 ]
  %69 = trunc nuw nsw i64 %68 to i32
  br label %73

70:                                               ; preds = %117
  %71 = add nuw nsw i64 %61, 1
  %72 = icmp eq i64 %71, 33
  br i1 %72, label %64, label %60, !llvm.loop !18

73:                                               ; preds = %67, %83
  %74 = phi i32 [ -1, %67 ], [ %84, %83 ]
  %75 = phi i32 [ 0, %67 ], [ %105, %83 ]
  %76 = phi i32 [ 0, %67 ], [ %104, %83 ]
  %77 = add nsw i32 %74, %63
  %78 = mul nuw nsw i32 %77, 66
  %79 = add nuw nsw i32 %78, %69
  br label %86

80:                                               ; preds = %83
  %81 = add nuw nsw i64 %68, %62
  %82 = icmp eq i32 %104, 3
  br i1 %82, label %114, label %108

83:                                               ; preds = %103
  %84 = add nsw i32 %74, 1
  %85 = icmp eq i32 %84, 2
  br i1 %85, label %80, label %73, !llvm.loop !19

86:                                               ; preds = %73, %103
  %87 = phi i32 [ -1, %73 ], [ %106, %103 ]
  %88 = phi i32 [ %75, %73 ], [ %105, %103 ]
  %89 = phi i32 [ %76, %73 ], [ %104, %103 ]
  %90 = or i32 %87, %74
  %91 = icmp eq i32 %90, 0
  br i1 %91, label %103, label %92

92:                                               ; preds = %86
  %93 = add nsw i32 %79, %87
  %94 = zext i32 %93 to i64
  %95 = getelementptr inbounds nuw [2 x [2244 x i32]], ptr %1, i64 0, i64 %26, i64 %94
  %96 = load i32, ptr %95, align 4, !tbaa !8
  %97 = icmp ne i32 %96, 0
  %98 = zext i1 %97 to i32
  %99 = add i32 %89, %98
  %100 = icmp eq i32 %96, 16711680
  %101 = zext i1 %100 to i32
  %102 = or i32 %88, %101
  br label %103

103:                                              ; preds = %86, %92
  %104 = phi i32 [ %89, %86 ], [ %99, %92 ]
  %105 = phi i32 [ %88, %86 ], [ %102, %92 ]
  %106 = add nsw i32 %87, 1
  %107 = icmp eq i32 %106, 2
  br i1 %107, label %83, label %86, !llvm.loop !20

108:                                              ; preds = %80
  %109 = getelementptr inbounds nuw [2 x [2244 x i32]], ptr %1, i64 0, i64 %26, i64 %81
  %110 = load i32, ptr %109, align 4, !tbaa !8
  %111 = icmp ne i32 %110, 0
  %112 = icmp eq i32 %104, 2
  %113 = select i1 %111, i1 %112, i1 false
  br i1 %113, label %114, label %117

114:                                              ; preds = %108, %80
  %115 = icmp eq i32 %105, 0
  %116 = select i1 %115, i32 65280, i32 16711680
  br label %117

117:                                              ; preds = %108, %114
  %118 = phi i32 [ %116, %114 ], [ 0, %108 ]
  %119 = getelementptr inbounds nuw [2 x [2244 x i32]], ptr %1, i64 0, i64 %59, i64 %81
  store i32 %118, ptr %119, align 4, !tbaa !8
  %120 = add nuw nsw i64 %68, 1
  %121 = icmp eq i64 %120, 65
  br i1 %121, label %70, label %67, !llvm.loop !21
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #1

; Function Attrs: mustprogress nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #2

declare i32 @simRand(...) local_unnamed_addr #3

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @simFlush(...) local_unnamed_addr #3

attributes #0 = { noreturn nounwind uwtable "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #2 = { mustprogress nocallback nofree nounwind willreturn memory(argmem: write) }
attributes #3 = { "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"Debian clang version 20.1.8 (++20250708063551+0c9f909b7976-1~exp1~20250708183702.136)"}
!5 = distinct !{!5, !6, !7}
!6 = !{!"llvm.loop.mustprogress"}
!7 = !{!"llvm.loop.unroll.disable"}
!8 = !{!9, !9, i64 0}
!9 = !{!"int", !10, i64 0}
!10 = !{!"omnipotent char", !11, i64 0}
!11 = !{!"Simple C/C++ TBAA"}
!12 = distinct !{!12, !6, !7}
!13 = distinct !{!13, !6, !7}
!14 = distinct !{!14, !6, !7}
!15 = distinct !{!15, !6, !7}
!16 = distinct !{!16, !6, !7}
!17 = distinct !{!17, !7}
!18 = distinct !{!18, !6, !7}
!19 = distinct !{!19, !6, !7}
!20 = distinct !{!20, !6, !7}
!21 = distinct !{!21, !6, !7}
