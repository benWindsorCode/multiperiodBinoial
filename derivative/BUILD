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