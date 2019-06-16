cc_library(
        name = "derivative-lib",
        srcs = ["derivative.cc"],
        hdrs = ["derivative.h"],
        visibility = ["//main:__pkg__"],
        deps = [
            "//stock:stock-lib",
        ],
)

cc_library(
        name = "europeanCall-lib",
        srcs = ["europeanCall.cc"],
        hdrs = ["europeanCall.h"],
        visibility = ["//main:__pkg__"],
        deps = [
                "//derivative:derivative-lib",
        ],
)

cc_library(
        name = "europeanPut-lib",
        srcs = ["europeanPut.cc"],
        hdrs = ["europeanPut.h"],
        visibility = ["//main:__pkg__"],
        deps = [
                "//derivative:derivative-lib",
        ],
)